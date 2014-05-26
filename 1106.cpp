#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <cassert>
#include <cstdlib>

using namespace std;

typedef pair<int, int> link_t;
multimap<link_t, int> suite;

const int team_A = 0;
const int team_B = 1;

void process_input()
{
	string line, word;

	assert(getline(cin, line));

	int n = atoi(line.c_str());
	assert(n >= 1 && n <= 100);

	for (int i = 1; i <= n && getline(cin, line); i++) {
		istringstream is(line);
		int friend1 = i;
		while (is >> word) {
			if (word == "0") break;

			int friend2 = atoi(word.c_str());
			suite.insert({{friend1, friend2}, team_A});
		}
	}
}

ostream& operator<<(ostream& os, const pair<link_t, int>& elem)
{
		os << elem.first.first << "->" << elem.first.second << ": "
			<< elem.second;
		return os;
}

template<class T>
void print(T& container)
{
	for (auto& elem : container)
		cout << elem << endl;
}

void toggle_switch(pair<const link_t, int>& link)
{
	link.second = (link.second == team_A) ? team_B : team_A;
}

int main()
{
	process_input();

	bool balanced;
	int team_ba, key_ba;
	multimap<link_t, int>::iterator it_ba;

	int cnt {0};
	do {
		balanced = true;
		cout << "Num: " << ++cnt << endl;
		cout << "A -> B: "<< endl;
		print(suite);
		for (auto pos_ab = suite.begin(); pos_ab != suite.end(); ++pos_ab)
			for (auto pos_ba = suite.begin(); pos_ba != suite.end(); ++pos_ba) {
				if (pos_ab->first.first == pos_ba->first.second &&
						pos_ab->first.second == pos_ba->first.first) {
					if (pos_ab->second == pos_ba->second) {
						toggle_switch(*pos_ba);
						balanced = false;
						key_ba = pos_ba->first.first;
						team_ba = pos_ba->second;
						it_ba = pos_ba;
						goto switch_others;
					}
				}
			}
switch_others:
		cout << "A -> B: "<< endl;
		print(suite);
		if (!balanced)
			for (auto pos = it_ba; pos != suite.end(); ++pos)
				if (pos->first.first == key_ba && pos->second != team_ba) {
					toggle_switch(*pos);
			}
	} while (!balanced);

}
