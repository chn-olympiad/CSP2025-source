#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll N = 1e6 + 5;
ll n, a[10];
char s[N];

int main() {
//	freopen("number.in", number, stdin);
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; ++i) {
		if (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8'
		        || s[i] == '9') {
			a[s[i] - '0']++;	
		}
	}
	for (int i = 9; i >= 0; --i) {
		for (int j = 1; j <= a[i]; ++j)
			printf("%lld", i);
	}
}//
