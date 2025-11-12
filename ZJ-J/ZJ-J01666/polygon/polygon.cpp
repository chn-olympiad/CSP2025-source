#include<bits/stdc++.h>
using namespace std;
const long long M=998244353,N=5005;
long long n,a[N],ans,b[N],dp[N][N],mx;
void dfs(int j,int m,int x,int s){
	if(s>x){
		ans++;
		ans%=M;
	}
	for(int i=j+1;i<=m;i++){
		dfs(i,m,x,s+a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		mx=max(mx,a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=2;i++){
		b[i]=b[i-1]+a[i];
	}
	for(int i=3;i<=n;i++){
		b[i]=b[i-1]+a[i];
		if(b[i-1]>a[i]){
			dfs(0,i-1,a[i],0);
		}
	}
	printf("%lld",ans%M);
	return 0;
}
