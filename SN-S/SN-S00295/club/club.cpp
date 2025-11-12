#include <bits/stdc++.h>
#define ll long long
using namespace std;
int t;
int n;
struct A{
	int a,b,c;
}ls[100010];
int ans;
void dfs(int ax,int bx,int cx,int cnt,int lsans){
	if(cnt>n){
		ans=max(ans,lsans);
		return;
	}
	if(ax<n/2){
		dfs(ax+1,bx,cx,cnt+1,lsans+ls[cnt].a);
	}
	if(bx<n/2){
		dfs(ax,bx+1,cx,cnt+1,lsans+ls[cnt].b);
	}
	if(cx<n/2){
		dfs(ax,bx,cx+1,cnt+1,lsans+ls[cnt].c);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>ls[i].a>>ls[i].b>>ls[i].c;
		}
		dfs(0,0,0,1,0);
		cout<<ans<<"\n";
	}
	return 0;
}
