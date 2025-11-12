#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;int a[N],b[N],c[N],n,mx;
void dfs(int l,int s,int x,int y,int z){
	if(x>n/2||y>n/2||z>n/2) return;
	if(l>n){
		mx=max(mx,s);
		return;
	}dfs(l+1,s+a[l],x+1,y,z);
	dfs(l+1,s+b[l],x,y+1,z);
	dfs(l+1,s+c[l],x,y,z+1);
}int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int t;cin>>t;
	while(t--){
		cin>>n;mx=0;
		for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
		dfs(1,0,0,0,0);cout<<mx<<'\n';
	}return 0;
}
