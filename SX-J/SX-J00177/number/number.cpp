#include <bits/stdc++.h>
using namespace std;
//48 - 57

bool cmp (int a,int b) {
	return a > b;
}

int main () {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int k = 0;
	int num[100005] = {};
	char a[100005];
	int l = s.length();
	cin >> s;
	for (int i = 0;i <= s.length();i++) {
		if (s[i] >= 48 && s[i] <= 57) {
			a[k] = s[i];
			k++;
		}
	}

	for (int i = 0;i <= k - 1;i++) {
		num[i] = a[i] - '0';
	}

	sort(num,num + k,cmp);

	if (num[0] == 0) {
		cout << 0;
		return 0;
	}

	for (int i = 0;i <= k - 1;i++) {
		cout << num[i];
	}

	return 0;
}