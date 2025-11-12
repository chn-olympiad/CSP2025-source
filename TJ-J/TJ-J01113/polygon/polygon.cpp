#include<bits/stdc++.h>
using namespace std;
int a[5001];
int n;
long long ans=0;
void dfs(int i,int maxn,int cnt){
	if(i>=3&&2*maxn<cnt) ans++;
	if(ans>=998244353) ans-=998244353;
	for(int j=i+1;j<=n;++j){
		dfs(j,max(maxn,a[j]),cnt+a[j]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	if(n<3){
		printf("%d",0);
		return 0;
	}
	dfs(0,0,0);
	printf("%lld",ans);
	return 0;
}
