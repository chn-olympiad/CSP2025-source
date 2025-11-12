#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 5,M = 5e6 + 5,base = 37,p = 998244353;
int n,q,len[N],ok[M],ok2[M];
ll pw[M],h[M],h2[M],h3[M],h4[M];
char s[M],s2[M];

ll calc(int l,int r) {
	return ((h3[r] - h3[l - 1] * pw[r - l + 1] % p) % p + p) % p;
}

ll calc2(int l,int r) {
	return ((h4[r] - h4[l - 1] * pw[r - l + 1] % p) % p + p) % p;
}

void solve() {
	scanf("%d%d",&n,&q);
	pw[0] = 1;
	for(int i = 1;i <= 5000000;i++) pw[i] = pw[i - 1] * base % p;
	for(int i = 1;i <= n;i++) {
		scanf("%s",s + 1);
		len[i] = strlen(s + 1);
		for(int j = 1;j <= len[i];j++) h[i] = (h[i] * base % p + s[j] - 'a') % p;
		scanf("%s",s + 1);
		for(int j = 1;j <= len[i];j++) h2[i] = (h2[i] * base % p + s[j] - 'a') % p;
		cout << (s + 1) << "\n";
	}
	while(q--) {
		scanf("%s%s",s + 1,s2 + 1);
		int m = strlen(s + 1);
		for(int i = 0;i <= m + 1;i++) ok[i] = ok2[i] = false;
		ok[0] = true;
		ok2[m + 1] = true;
		for(int i = 1;i <= m;i++) ok[i] = (ok[i - 1] & (s[i] == s2[i])),h3[i] = (h3[i - 1] * base % p + s[i] - 'a') % p,h4[i] = (h4[i - 1] * base % p + s2[i] - 'a') % p;
		for(int i = m;i >= 1;i--) ok2[i] = (ok2[i + 1] & (s[i] == s2[i]));
		int ans = 0;
		for(int i = 1;i <= n;i++)
			for(int j = 1;j + len[i] - 1 <= m;j++) {
				if(!ok[j - 1] || !ok2[j + len[i]]) continue;
				if(calc(j,j + len[i] - 1) == h[i] && calc2(j,j + len[i] - 1) == h2[i]) ans++;
			}
		printf("%d\n",ans);
	}
}

int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int T = 1;
//	scanf("%d",&T);
	while(T--) solve();
	return 0;
}