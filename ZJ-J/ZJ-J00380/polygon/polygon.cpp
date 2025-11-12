#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const long long modd=998244353;
int n,a[5005],sum,ans,now;
long long b[5005];
bool vis[5005],flag=false;
void dfs(int k){
	if(k>n){
		for(int i=n;i>=1;i--){
			if(vis[i]){
				now=i;
				break;
			}
		}
		if(sum>a[now]*2)ans=(ans+1)%mod;
		return ;
	}
	sum+=a[k];
	vis[k]=true;
	dfs(k+1);
	sum-=a[k];
	vis[k]=false;
	dfs(k+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1)flag=true;
	}
	sort(a+1,a+n+1);
	if(flag||n<=25){
		dfs(1);
		printf("%d",ans);
	}
	else{
		long long summ=0;
		for(long long i=3;i<=n;i++){
			long long anss=1;
			memset(b,0,sizeof b);
			for(long long j=1;j<=i;j++)b[j]=n-j+1;
			for(long long j=i;j>=2;j--){
				for(long long k=1;k<=i;k++){
					if(b[k]%j==0){
						b[k]/=j;
						break;
					}
				}
			}
			for(long long j=1;j<=i;j++)anss=(anss*b[j])%modd;
			summ=(summ+anss)%modd;
		}
		printf("%lld",summ);
	}
	return 0;
}
