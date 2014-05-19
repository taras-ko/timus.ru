#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <string>
#include <functional>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream in("1837.test");
	typedef vector<vector<string>> team_t;
	team_t teams;

	string line;
	while (getline(in, line)) {
		istringstream iss(line);
		istream_iterator<string> first_iit{iss};
		istream_iterator<string> last_iit{};
		vector<string> words {first_iit, last_iit};
		teams.push_back(words);
	}

	hash<string> str_hash;
	for (team_t::iterator it = teams.begin(); it != teams.end(); ++it) {
		for (vector<string>::iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2) {
			cout << str_hash(*it2) << ' ';
		}
		cout << endl;
	}
}
