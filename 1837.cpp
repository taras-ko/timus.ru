#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

int nametoi(const string& name)
{
	int val {0};
	for (int i = 0; i < name.length(); i++)
		val += name[i] * (i + 1);

	return val;
}


template<class T>
int find(T& elem, T& base, vector<set<T>>& sets)
{
	find(elem, base, sets
}

template<class T>
void print_set(T& set)
{
	for (auto& elem : set)
		cout << elem << ' ';
}

typedef set<string> Set;
int main(int argc, char *argv[])
{
	ifstream in("1837.test");

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

	find("Oparin", "Isenbaev", teams);

	print_set(members);
}
