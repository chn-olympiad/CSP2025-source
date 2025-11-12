#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int N = 505;
int n,m,c[N],ans=0,s2[N],p[N];
string s="";
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	s[0]='a';
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i ++) {
		cin >> c[i];
		p[i]=c[i];
	}
	int cnt=0;
	sort(c+1,c+1+n);
	for (int i = 1; i <= n; i ++) {
		for (int k = 1;k <= n;k ++) p[i]=c[i];
		cnt=0;
		if (s[i] == '1' && p[i] >= 0) {
			cnt ++;
			for (int j = i+1; j <= n; j ++) p[j] --;
		}
		if (cnt == m) ans ++;
		cout << cnt << " ";
	}
	

	cout << 2+n;
	return 0;
	fclose(stdin);
	fclose(stdout);
}