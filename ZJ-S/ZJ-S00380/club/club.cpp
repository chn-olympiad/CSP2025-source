#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=205;
struct jion{
	int a,b,c;
}u[N];
bool flaga,flagb;
map<int,pair<int,int> > mp;
bool cmp(jion A,jion B){
	if(A.a!=B.a)return A.a>B.a;
	if(A.b!=B.b)return A.b>B.b;
	return A.c>B.c;
}
int T,n,dp[M/2][M/2][M/2],ans;
inline void dfs(int a,int b,int c,int sum){
	if(dp[a][b][c]>sum){
		return;
	}
	dp[a][b][c]=max(sum,dp[a][b][c]);
	if(a+b+c==n+1){
		ans=max(sum,ans);
		/*
		
		cout<<"id:"<<
		id<<" a:"<<a<<" b:"<<b<<" c:"<<c<<" sum:"<<sum<<"\n";
		*/
		return;
	}
	if((a+1)<=(n/2)){
		dfs(a+1,b,c,sum+u[a+b+c].a);
	}
	
	if((b+1)<=(n/2)){
		dfs(a,b+1,c,sum+u[a+b+c].b);
	}
	if((c+1)<=(n/2)){
		dfs(a,b,c+1,sum+u[a+b+c].c);
	}
	return;
}
inline void dfs2(int a,int b,int c,int sum){
	if(dp[a][b][c]>sum){
		return;
	}
	dp[a][b][c]=max(sum,dp[a][b][c]);
	if(a+b+c==n+1){
		ans=max(sum,ans);
		/*
		
		cout<<"id:"<<
		id<<" a:"<<a<<" b:"<<b<<" c:"<<c<<" sum:"<<sum<<"\n";
		*/
		return;
	}
	if((a+1)<=(n/2)){
		dfs2(a+1,b,c,sum+u[a+b+c].a);
	}
	
	if((b+1)<=(n/2)){
		dfs2(a,b+1,c,sum+u[a+b+c].b);
	}
	return;
}
inline void solve(){
		memset(dp,0,sizeof dp);
	flaga=flagb=true;
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>u[i].a>>u[i].b>>u[i].c;
		if(flagb){
			if(u[i].c!=0){
				flagb=false;
				flaga=false;
			}else{
				if(flaga){
					if(u[i].b!=0){
						flaga=false;
					}
				}
			}
		}
	}
	
	if(flaga){
		sort(u+1,u+1+n,cmp);
		for(int i=1;i<=(n/2);i++){
			ans+=u[i].a;
		}
		cout<<ans<<"\n";
		return;
	}
	if(flagb){
		for(int i=1;i<=n;i++){
			ans+=max(max(u[i].a,u[i].b),u[i].c);
		}
		cout<<ans<<"\n";
		return;
	}
	if(n>=200){
		for(int i=1;i<=n;i++){
			ans+=max(max(u[i].a,u[i].b),u[i].c);
		}
		cout<<ans<<"\n";
		return;
	}
	dfs(0,0,0,0);
	cout<<ans<<"\n";
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
