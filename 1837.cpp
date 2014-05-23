#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

template<class T>
void print(T& set)
{
	for (auto& elem : set)
		cout << elem << ' ';
	cout << endl;
}

typedef set<string> Set;

Set& operator+=(Set& lvalue, const Set& rvalue) {
	for (auto& elem : rvalue)
		lvalue.insert(elem);

	return lvalue;
}
void evaluate_members(vector<Set>& teams, Set& members, string& base_member)
{
	vector<Set> results;

	Set search_set {base_member};
	while (!search_set.empty()) {
		results.push_back(search_set);
		Set next_search_set {};
		for (auto& member : search_set) {
			for (auto team_it = teams.begin(); team_it != teams.end(); team_it++) {
				auto& team = *team_it;
				if (team.find(member) != team.end()) {
					next_search_set += team;
					teams.erase(team_it);
				}
			}
			next_search_set.erase(member);
		}
		search_set = next_search_set;
	}
	Set others;
	for (auto& team : teams)
		others += team;
	results.push_back(others);

	for (auto it = results.begin(); it < results.end() - 1; it++) {
		static int level;
		cout << "level " << level++ << endl;
		auto& team = *it;
		print(team);
	}
	cout << "undefined" << endl;
	print(results.back());
}

int main(int argc, char *argv[])
{
	const char *file = "1837.test";
	string base_member {"Isenbaev"};
	if (argc == 2)
		file = argv[1];

	ifstream in(file);

	string name, line;
	Set members;
	vector<Set> teams;

	while (getline(in, line)) {
		Set team;
		istringstream is_team(line);
		while (is_team >> name) {
			members.insert(name);
			team.insert(name);

		}
		teams.push_back(team);
		team.empty();
	}

	cout << "Looking for: " << base_member << endl << "--\n";

	evaluate_members(teams, members, base_member);

//	print(members);
}
