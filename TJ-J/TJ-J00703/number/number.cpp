#include<bits/stdc++.h>
using namespace std;
const int n = 1000001;
string s[n];
string a[n] = { };
int main() {
    freopen("number.in", "r","stdin");
    freopen("number.out", "w","stdout");
	for(int i = 0; i < 1; i++) {
		cin >> s[i];
		a[i] = s[i];
		for(int j = s[i].size(); j > 0; j--) {
			if(a[j] == "1" || a[j] == "2" || a[j] == "3" || a[j] == "4" || a[j] == "5" || a[j] == "6" || a[j] == "7" || a[j] == "8" || a[j] == "9") {
				cout << a[j];
			}
		}
	}
	return 0;
}
