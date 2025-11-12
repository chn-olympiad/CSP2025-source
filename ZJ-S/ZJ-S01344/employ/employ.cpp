#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int N=50;

int n,m;
int c[N];
bool used[N];
int p[N];
string s;
int ans;

void dfs(int d,int g) {
	if(d==n+1) {
		if(n-g>=m) ans++;
		return ;
	}
	for(int i=1; i<=n; i++) {
		if(used[i]) continue;
		used[i]=1;
		if(g>=c[i]||s[d]=='0') dfs(d+1,g+1);
		else dfs(d+1,g);
		used[i]=0;
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1; i<=n; i++) {
		cin>>c[i];
	}
	dfs(1,0);
	cout<<ans;
}
//rp++