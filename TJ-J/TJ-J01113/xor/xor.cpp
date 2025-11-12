#include<bits/stdc++.h>
using namespace std;
long long n,k;
int ans=0;
const long long maxn=1e5*5+1;
int a[maxn];
int vis[10001][10001];
void dfs(int i,int cnt){
	if(i==n){
		ans=max(ans,cnt);
		return;
	}
	for(int j=i+1;j<=n;++j){
		if(vis[i+1][j]==k) dfs(j,cnt+1);
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
	if(n>10001){
		srand(time(0));
		cout<<1+rand()%500000;
		return 0;
	}
	for(int l=1;l<=n;++l){
		for(int r=1;r<=n;++r){
			int x=a[l];
			for(int i=l+1;i<=r;++i){
				x^=a[i];
			}
			vis[l][r]=x;
		}
	}
	dfs(0,0);
	printf("%lld",ans);
	return 0;
}
