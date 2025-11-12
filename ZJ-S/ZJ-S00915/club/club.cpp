#include<bits/stdc++.h>
#define For(i,l,r) for(int i=(l);i<=(r);++i)
using namespace std;
const int N=1e5+10;
int T,n,a[N][4],ans;
void dfs(int x,int s1,int s2,int s3,int sum){
	if(s1>n/2||s2>n/2||s3>n/2) return ;
	if(x==n+1){
		ans=max(ans,sum);
		return ;
	}
	dfs(x+1,s1+1,s2,s3,sum+a[x][1]);
	dfs(x+1,s1,s2+1,s3,sum+a[x][2]);
	dfs(x+1,s1,s2,s3+1,sum+a[x][3]);
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		For(i,1,n) For(j,1,3) cin>>a[i][j];
		ans=0;
		dfs(1,0,0,0,0);
		cout<<ans<<"\n";
	}
	return 0;
}

