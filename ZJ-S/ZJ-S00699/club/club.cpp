#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int maxn=1e5+10;
int t,n;
ll x[maxn][4];
ll dfs(int i,int a,int b,int c,ll s){
	if(i>n) return s;
	ll ans=0;
	if(a<=n/2-1) ans=max(ans,dfs(i+1,a+1,b,c,s+x[i][1]));
	if(b<=n/2-1) ans=max(ans,dfs(i+1,a,b+1,c,s+x[i][2]));
	if(c<=n/2-1) ans=max(ans,dfs(i+1,a,b,c+1,s+x[i][3]));
	return ans;
}
int a1[maxn];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		bool flaga=1,flagb=1,flagc=1;
		cin>>n;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=3; j++){
				cin>>x[i][j];
				if((j==2||j==3)&&x[i][j]!=0) flaga=0;
				else if(j==3&&x[i][j]!=0) flagb=0;
				else if(!(x[i][j]==0||x[i][j]==20000)) flagc=0;
				if(j==1) a1[i]=x[i][j];
			}
		if(n<=30)
			cout<<dfs(1,0,0,0,0)<<'\n';
		else if(n==100000&&flaga){
			sort(a1+1,a1+n+1,cmp);
			ll ans=0;
			for(int i=1; i<=n/2; i++)
				ans+=a1[i];
			cout<<ans<<'\n';
		}
		else cout<<dfs(1,0,0,0,0)<<'\n';
	}
	return 0;
}
