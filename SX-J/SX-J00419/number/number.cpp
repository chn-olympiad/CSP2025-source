#include <bits/stdc++.h>
using namespace std;

int main() {

    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

	string s;
	cin >> s;
	int ver = s.size();
	for (int i = 0; i < ver ; i++) {
		if (s[i] < s[i + 1]) {
			swap(s[i], s[i + 1]);
		}

	}
	for (int i = 0; i < ver; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			cout << s[i];
		}
	}




	return 0;
}
