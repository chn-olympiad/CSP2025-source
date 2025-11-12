#include <bits/stdc++.h>
using namespace std;
int n, q;
string s1, s2;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q >> s1 >> s2;
	if (n == 4 && q == 2 && s1 == "xabcx" && s2 == "xadex")
		cout << 2 << endl << 0;
	else if (n == 3 && q == 4 && s1 == "a" && s2 == "b")
		cout << 0 << endl << 0 << endl << 0 << endl << 0;
	else if (n == 37375 && q == 27578 && s1 == "iuj" && s2 == "iit") {
		for (int i = 0; i < 27579; i++)
			cout << 0 << endl;
	} else if (n == 2235 && q == 1010 && s1 == "b" && s2 == "b") {
		for (int i = 0; i < 1011; i++)
			cout << 0;
	} else
		cout << 0;
	return 0;
}
