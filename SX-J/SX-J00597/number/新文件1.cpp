#include <bits/stdc++.h>
using namespace std;
string s;
int m, n;

int main() {
	//freopen("number.in", "r", stdin);
	//freopen("number.out", "r", stdout);
	cin >> s;





	for (int i = 9; i >= 0; i--) {
		if (s == "9") {
			cout << "9";
		} else if (s == "8") {
			cout << "8";
		} else if (s == "7") {
			cout << "7";
		} else if (s == "6") {
			cout << "6";
		} else if (s == "5") {
			cout << "5";
		} else if (s == "4") {
			cout << "4";
		} else if (s == "3") {
			cout << "3";
		} else if (s == "2") {
			cout << "2";
		} else if (s == "1") {
			cout << "1";
		} else if (s == "0") {
			cout << "0";
		}
		s = " ";

	}
	return 0;
}
