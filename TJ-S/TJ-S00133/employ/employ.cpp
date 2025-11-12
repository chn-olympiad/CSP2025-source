#include<bits/stdc++.h>
using namespace std;
const int MX = 501;
int s[MX],c[MX];

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		char x;
		cin >> x;
		s[i] = (int)x;
	}
	for (int i = 1; i <= n; i++) cin >> c[i];
	int cnt = 0, ans = 1;
	while (s[cnt - 1] == 1) cnt++;
	for (int i = 1; i <= cnt; i++) ans *= i;
	cout << ans;
	return 0;
} 
