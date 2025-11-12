#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int mod=998244353;
int n,a[5005],ans=0;
bool vis[5005];
void dfs(int dep,int maxn,int sum,int cnt){
	if(cnt>=3&&sum>maxn*2) ans=(ans+1)%mod;
	for(int i=dep;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(i+1,a[i],sum+a[i],cnt+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	dfs(1,0,0,0);
	printf("%d\n",ans);
	return 0;
}