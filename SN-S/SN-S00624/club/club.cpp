#include<bits/stdc++.h>
using namespace std;
int T,n,a[100100],b[100100],c[100100],maxx;
void dfs(int o,int ans,int as,int bs,int cs){
	if(o>n){
		maxx=max(maxx,ans);
		return;
	}
	if(as<n/2)dfs(o+1,ans+a[o+1],as+1,bs,cs);
	if(bs<n/2)dfs(o+1,ans+b[o+1],as,bs+1,cs);
	if(cs<n/2)dfs(o+1,ans+c[o+1],as,bs,cs+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		maxx=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		dfs(1,a[1],1,0,0);
		dfs(1,b[1],0,1,0);
		dfs(1,c[1],0,0,1);
		cout<<maxx<<'\n';
	} 
	return 0;
}
