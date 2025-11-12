#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
const int L=2001;
int t,n,dp[L][L];
struct node{
	int x,y,z;
}a[N];
int zd(int x,int y,int z){
	return max(x,max(y,z));
}
bool cmp(node c,node d){
	return zd(c.x,c.y,c.z)>zd(d.x,d.y,d.z);
}
int dfs(int x,int f1,int f2,int f3,int ans){
	if(f1>n/2||f2>n/2||f3>n/2) return 0;
	if(x>n) return ans;
	dp[f1][f2]=max(dp[f1][f2],zd(dfs(x+1,f1+1,f2,f3,ans+a[x].x),dfs(x+1,f1,f2+1,f3,ans+a[x].y),dfs(x+1,f1,f2,f3+1,ans+a[x].z)));
	if(f1<L&&f2<L&&dp[f1][f2]){
		return dp[f1][f2];
	}
	return zd(dfs(x+1,f1+1,f2,f3,ans+a[x].x),dfs(x+1,f1,f2+1,f3,ans+a[x].y),dfs(x+1,f1,f2,f3+1,ans+a[x].z));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		}
		printf("%lld\n",dfs(1,0,0,0,0));
		if(t!=n&&t!=0) memset(dp,0,sizeof(dp));
	}
	return 0;
} 
