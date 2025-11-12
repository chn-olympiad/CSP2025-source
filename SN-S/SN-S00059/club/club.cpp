#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[500005][4];
int mx;
inline void dfs(int cnt,int a1,int b1,int c1,int x){
	if(x>n){
		mx=max(mx,cnt);
		return;
	}

	if(a1!=n/2){
		dfs(cnt+a[x][1],a1+1,b1,c1,x+1);
	}
	if(b1!=n/2){
		dfs(cnt+a[x][2],a1,b1+1,c1,x+1);
	}if(c1!=n/2){
		dfs(cnt+a[x][3],a1,b1,c1+1,x+1);
	}
	
}
void hs(){
	memset(a,0,sizeof(a));
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
	}
	dfs(0,0,0,0,1);
	cout<<mx<<'\n';
	mx=0;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		hs();
		
	}
	return 0;
} //dp[i][1]=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))+a[i].a;
