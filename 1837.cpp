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
namespace local {

template<class T>
int find(T& elem, T& base, vector<set<T>>& v)
{
	static int i;
	static int descent;

	if (i == v.size()) // walked through all vector
		return -1;

	set<T>& cur_set = v[i];
	auto elem_it = cur_set.find(elem);
	auto base_it = cur_set.find(base);
	auto outside = cur_set.end();
#if 1
	if (elem_it != outside && base_it != outside) // found direct link elem <--> base
		return (elem_it == base_it) ? 0 : 1;
	else if (elem_it != outside && cur_set.size() > 1) { // found entry point for undirect relation
		cur_set.erase(elem_it); // exclude current element;
		auto intermedium = cur_set.begin(); // switch to next intermedium element
		T elem = *intermedium;
		return find(elem, base, v);
	} else { // switch to next set
		i++;
		return find(elem, base, v);
	}
#endif
}

} // namespace local

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
	vector<set<string>> teams;

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

	string elem {"Chevdar"};
	string base {"Isenbaev"};
	cout << "Looking for: " << base << endl << "--\n";

#if 0
	for (auto& team : teams) {
		auto elem_it = team.find(elem);
		auto outside = team.end();
		if (elem_it != outside) { // found searching entry point
#endif
			cout << "Find target: " << elem << endl;
			int res = local::find(elem, base, teams);
			cout << "Find result: " << res << endl;
#if 0
		}
	}

	print_set(members);
#endif
}
