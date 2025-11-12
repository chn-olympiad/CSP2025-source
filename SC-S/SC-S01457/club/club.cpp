#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int vis[4];
int n;
int ans=0;
int q1[N],q2[N],q3[N];
void dfs(int dep,int a,int b,int c,int da,int db,int dc){
	if(da>n/2||db>n/2||dc>n/2)
	return;
	if(dep==n){
		ans=max(ans,a+b+c);
		return;
	}
	for(int i=1;i<=3;i++){
		if(i==1){
			dfs(dep+1,a+q1[dep+1],b,c,da+1,db,dc);
		}
		if(i==2){
			dfs(dep+1,a,b+q2[dep+1],c,da,db+1,dc);
		}
		if(i==3){
			dfs(dep+1,a,b,c+q3[dep+1],da,db,dc+1);
		}
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>q1[i]>>q2[i]>>q3[i];
		}
		dfs(0,0,0,0,0,0,0);
		cout<<ans<<'\n';
		ans=0;
	}
	return 0;
}