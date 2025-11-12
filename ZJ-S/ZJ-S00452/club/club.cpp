#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,a[100005],b[100005],c[100005],ans;
void dfs(int x,int y,int z,int s,int st) {
	if(s==n) {
		ans=max(ans,st);
		return;
	}
	if(x<n/2)dfs(x+1,y,z,s+1,st+a[s+1]);
	if(y<n/2)dfs(x,y+1,z,s+1,st+b[s+1]);
	if(z<n/2)dfs(x,y,z+1,s+1,st+c[s+1]);
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		ans=0;
		cin>>n;
		for(int i=1; i<=n; i++)
			cin>>a[i]>>b[i]>>c[i];
		dfs(0,0,0,0,0);
		cout<<ans<<"\n";
	}
	return 0;
}
//csprp++;