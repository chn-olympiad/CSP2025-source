#include <bits/stdc++.h>
using namespace std;
char s[1000000];
long long m;

int main() {
//	freopen("number,in", "r", stdin);
//	freopen("number,out", "w", stdout);
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> s[i];
		if (s[i] > '0' && s[i] <= '9') {
			cout << s[i];
		}
	}





	return 0;

}



