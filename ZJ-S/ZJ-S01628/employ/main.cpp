#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int cnt;

int main() {
	assert(!system("g++ -o gen gen.cpp -O2 -static -std=c++14"));
	assert(!system("g++ -o bf bf.cpp -O2 -static -std=c++14"));
	assert(!system("g++ -o employ employ.cpp -O2 -static -std=c++14"));
	while (1) {
		assert(!system("./gen"));
		assert(!system("./bf"));
		assert(!system("./employ"));
		assert(!system("diff employ.out employ.ans"));
		cerr << "AC: " << ++cnt << "\n";
	}
	return 0;
}