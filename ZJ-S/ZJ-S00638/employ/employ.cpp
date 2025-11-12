#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[505],ans,f[505];
char d[505];
void dfs(int x,int s,int j){
	int nh=0;
	for(int i=1;i<=n;i++){
		if(!f[i]&&j>=a[i]) nh++;
	}
	if(x>n||j+s+nh==n){
		if(s>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(j<a[i]&&!f[i]){
			f[i]=1;
			if(d[x]==0) dfs(x+1,s,j+nh+1);
			else dfs(x+1,s+1,j+nh);
			f[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>d+1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[i]-='0';
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}