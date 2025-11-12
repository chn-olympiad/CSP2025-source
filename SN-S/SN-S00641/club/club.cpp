#include<bits/stdc++.h>
using namespace std;
long long t,n,ans,cna,cnb,cnc;
struct node{
	int a,b,c,mx;
}d[100010];
void dfs(int st,int a,int b,int c,long long va){
	if(st>n){
		ans=max(ans,va);
		return;
	}
	if(a<n/2)dfs(st+1,a+1,b,c,va+d[st].a);
	if(b<n/2)dfs(st+1,a,b+1,c,va+d[st].b);
	if(c<n/2)dfs(st+1,a,b,c+1,va+d[st].c);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		ans=cna=cnb=cnc=0;
		for(int i=1;i<=n;i++){
			cin>>d[i].a>>d[i].b>>d[i].c;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<'\n';
	}
	return 0;
}
