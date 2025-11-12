#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
const int mod=998244353;
int n,a[N],vis[N];
long long cnt;
bool check(){
	int maxx=0,sum=0;
	for(int i=1;i<=n;i++)if(vis[i])maxx=max(maxx,a[i]),sum+=a[i];
	return sum>2*maxx;
}
void dfs(int x){
	if(x==n+1){
		if(check())cnt=(cnt+1)%mod;
	}else{
		dfs(x+1);
		vis[x]=1;
		dfs(x+1);
		vis[x]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(n<=20){
		dfs(1);
		printf("%d",cnt);
	}else{
		cnt=1;
		for(int i=1;i<=n-3;i++){
			long long sum1=1,sum2=1;
			for(int j=0;j<i;j++)sum1*=(n-j),sum2*=(j+1);
			cnt=(cnt+sum1/sum2)%mod;
		}
		printf("%d",cnt);
	}
	return 0;
}
