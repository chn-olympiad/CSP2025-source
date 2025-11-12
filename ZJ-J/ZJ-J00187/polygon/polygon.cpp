#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=5e3+5;
int n;
int a[N];
long long ans;
void dfs(int k,int sum,int len,int maxx){
	if(k>n) return ;
	dfs(k+1,sum,len,maxx);
	sum+=a[k],len++,maxx=max(maxx,a[k]);
	if(len>=3&&sum>maxx*2){
		if(ans==mod) ans=0;
		else ans++;
	}
	dfs(k+1,sum,len,maxx);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dfs(1,0,0,0);
	printf("%lld",ans);
	return 0;
}