#include<bits/stdc++.h>
using namespace std;
int num[1000005];
int p = 0;
bool cmp (int a , int b) {
	return a > b;
}
int main () {
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	string s;
	cin >> s;
	int size = s.size();
	for (int i =0; i < size; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			p++;
			num[p] = s[i] - '0';
		}
	}
	sort(num + 1 , num + p + 1 , cmp);
	if (num[1] == 0) {
		cout << 0 << "\n";
		return 0;
	}
	for (int i = 1; i <= p; i++) {
		cout << num[i];
	}
	cout << "\n";
	return 0;
}
