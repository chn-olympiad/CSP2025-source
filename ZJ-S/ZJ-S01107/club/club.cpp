#include <bits/stdc++.h>
using namespace std;
int t,n,ans;
vector<vector<int> > v;
void dfs(int x, int a,int b,int c,int sum) {
	if(x>n) {
		ans=max(ans,sum);
		return;
	}
	if(a*2+2<=n) {
		dfs(x+1,a+1,b,c,sum+v[x][1]);
	}
	if(b*2+2<=n) {
		dfs(x+1,a,b+1,c,sum+v[x][2]);
	}
	if(c*2+2<=n) {
		dfs(x+1,a,b,c+1,sum+v[x][3]);
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--) {
		v.clear();
		ans=0;
		cin>>n;
		v.resize(n+1,vector<int>(4));
		for(int i=1; i<=n; i++) {
			cin>>v[i][1]>>v[i][2]>>v[i][3];
		}
		dfs(1,0,0,0,0);
		cout<<ans<<'\n';
	}
	return 0;
}