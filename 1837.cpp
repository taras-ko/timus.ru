#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <iterator>
#include <cassert>
#include <cstdlib>

using namespace std;

template<class T>
void printc(T& set)
{
	for (auto& elem : set)
		cout << elem << ' ';
	cout << endl;
}

template<class T>
void printv(T& vec) {
	int i = 0;
	for (auto& elem : vec) {
		printc(elem);
	}
}

typedef set<string> Set;

Set& operator+=(Set& lvalue, const Set& rvalue) {
	for (auto& elem : rvalue)
		lvalue.insert(elem);

	return lvalue;
}
vector<Set> evaluate_members(vector<Set>& teams, Set& members, string& base_member)
{
	vector<Set> results;

	Set search_set {base_member};
	while (!search_set.empty()) {
		results.push_back(search_set);
		Set next_search_set {};
		for (auto& member : search_set) {
			while (true) {
				bool found {false};
				for (auto team_it = teams.begin(); team_it != teams.end(); team_it++) {
					auto& team = *team_it;
					if (team.find(member) != team.end()) {
						next_search_set += team;
						teams.erase(team_it);
						found = true;
						break;
					}
				}
				if (!found) break;
			}
			next_search_set.erase(member);
		}
		search_set = next_search_set;
	}

	Set undef;
	for (auto& team : teams)
		undef += team;

	results.push_back(undef);

	return results;
}

int main(int argc, char *argv[])
{
	string base_member {"Isenbaev"};

	Set members;
	vector<Set> teams;

	string name, line;

	assert(getline(cin, line));
	int n = atoi(line.c_str());
	assert(n >= 1 && n <= 100);

	while (getline(cin, line)) {
		Set team;
		istringstream is_team(line);
		while (is_team >> name) {
			members.insert(name);
			team.insert(name);

		}
		teams.push_back(team);
		team.empty();
	}

	vector<Set> vals = evaluate_members(teams, members, base_member);
	if (vals.size() == 2) // there is no Isenbaev in list
		vals.erase(vals.begin());
#if 0
	printv(vals);
#endif
	map<string, int> results;

	int undefined_level = vals.size() - 1;

	while (!vals.empty()) {
		int level = vals.size() - 1;
		for (auto& member : vals.back())
			results.insert(pair<string, int>(member, level));
		vals.pop_back();
	}

	for (auto it = results.begin(); it != results.end(); it++) {
		cout << it->first << ' ';
		if (it->second == undefined_level)
			cout << "undefined";
		else
			cout << it->second;
		cout << endl;
	}
}
