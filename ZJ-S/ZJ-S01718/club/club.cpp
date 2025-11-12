#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N][4];
int dp[4][N/2];
int t,n,ans;
inline int read(){
	int res=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9'){
		res=res*10+c-'0';
		c=getchar();
	}
	return res;
}
inline void dfs(int step,int c1,int c2,int c3,int cnt){
	if(step>n){
		ans=max(ans,cnt);
		return;
	}
	if(c1<n/2) dfs(step+1,c1+1,c2,c3,cnt+a[step][1]);
	if(c2<n/2) dfs(step+1,c1,c2+1,c3,cnt+a[step][2]);
	if(c3<n/2) dfs(step+1,c1,c2,c3+1,cnt+a[step][3]);
	dfs(step+1,c1,c2,c3,cnt);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		n=read();
		for(int i=1;i<=n;i++){
			a[i][1]=read(),a[i][2]=read(),a[i][3]=read();
		}
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
