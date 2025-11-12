#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 1e6 + 10; 
string s;
LL n, tot;
LL a[N];

bool cmp(LL x, LL y){return x > y;}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	LL len = s.size();
	for(LL i = 0; i < len; i ++) {
		 if(s[i] >= '0' && s[i] <= '9') a[++ tot] = (LL)(s[i] - '0');
	}
//	
//	for(int i = 1; i <= tot; i ++) {
//		cout << a[i];
//	}
	sort(a + 1, a + tot + 1, cmp);
	for(LL i = 1; i <= tot; i ++) {
		cout << a[i];
	}
	return 0;
} 
