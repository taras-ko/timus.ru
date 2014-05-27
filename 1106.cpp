#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include <vector>
#include <cassert>
#include <cstdlib>

using namespace std;

class X {
	static int cnt;
	int id;
	int team;
	set<X*> friends;
public:
	X(): id(cnt++), team(0) {}
	friend
	ostream& operator<<(ostream& os, const X& x) {
		os << x.id;
	}
	int get_team() const { return team; }
	operator bool() const { return id != cnt - 1; }
	string get_id() const {
		stringstream ss;
		ss << id;
		return string(ss.str());
	}
	void switch_team() { team ^= 1; }
	bool has_opposite() const {
		for (auto& fr : friends)
			if (team != (*fr).team)
				return true;
		return false;
	}
	void add_friend(X* px) {
		friends.insert(px);
	}
	void print() const {
		cout << *this << '(' << this->team << ')' << "-> ";
		for (auto& fr : friends)
			cout << *fr << ' ';
		cout << endl;
	}
};

int X::cnt = 1; // first element

class Suite {
	X *suite;
public:
	Suite(int sz) {
		suite = new X[sz + 1];
	}
	~Suite() {
		delete []suite;
	}
	X& operator[](int n) {
		return suite[n - 1];
	}
	int colision_rate() const;
	void print() const;
	void print_result() const;
};


int Suite::colision_rate() const
{
	int rate = 0;
	for (X *px = suite; *px; px++)
		if (!px->has_opposite()) rate++;

	return rate;
}

void Suite::print() const
{
	for (X *px = suite; *px; px++)
		px->print();
	cout << "Rate: " << this->colision_rate() << endl;
}

void Suite::print_result() const
{
	int cnt = 0;
	string result;
	for (X *px = suite; *px; px++)
		if (px->get_team() == 0) {
			cnt++;
			result += px->get_id() + " ";
		}
	cout << cnt << endl;
	cout << result << endl;
}


//void process_input()
int main()
{
	string line, word;

	assert(getline(cin, line));

	int n = atoi(line.c_str());
	assert(n >= 1 && n <= 100);

	Suite suite(n);

	for (int i = 1; i <= n && getline(cin, line); ++i) {
		istringstream is(line);
		while (is >> word && word != "0") {
			int num = atoi(word.c_str());
			suite[i].add_friend(&suite[num]);
		}
	}

//	suite.print();
	while (suite.colision_rate() != 0) {
		for (int i = 1; i <= n; i++) {
			if (!suite[i].has_opposite())
				suite[i].switch_team();
		}
	}
	suite.print_result();
//	cout << endl;
//	suite.print();
}

#if 0
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
int main()
{
	process_input();
}
#endif

