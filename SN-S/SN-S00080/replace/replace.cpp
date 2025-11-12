//刘益铭 SN-S00080 西安高新第一中学
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n,q,ans;

string a[N],b[N];

void solve() {
	string s,t;
	ans = 0;
	cin >> s >> t;
	for(int i = 1;i<=n;i++) {
		int p = s.find(a[i]),tot = 0;
		string ss = s,tt = t;
		if(p == -1) continue;
		for(int j = p;j<=p+a[i].size()-1;j++) ss[j] = b[i][tot++];
		if(ss == tt) ans++;
	}
	cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i<=n;i++) cin >> a[i] >> b[i];
	while(q--) solve();
	return 0;
} 
