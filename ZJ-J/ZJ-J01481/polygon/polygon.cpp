#include<bits/stdc++.h>
using namespace std;
const int MAXN=5000+5;
const int inf=2147483647;
//
int n,mod=998244353,maxl=-inf;
int sum,ans,m;
int a[MAXN],sn[MAXN];
int o[MAXN];
bool one;
//
void dfs(int sp){
	if(sp>n){
		sum=0;
		m=0;
		maxl=-inf;
		for(int i=1;i<=n;++i){
			if(sn[i]==1){
				m++;
				sum+=a[i];
				maxl=max(maxl,a[i]);
			}
		}
		if(sum>maxl*2&&m>=3){
			ans++;
			ans=ans%mod;
		}
		return ;
	}
	sn[sp]=1;
	dfs(sp+1);
	sn[sp]=0;
	dfs(sp+1);
}
//
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		if(a[i]!=1)one=1;
	}
	if(one==0){
		int x=0,shang=1,xia=1;
		for(int i=3;i<=n;++i){
			if(i==3){
				for(int j=3;j>=1;--j){
					shang*=n-j+1;
				}
				for(int j=3;j>=1;--j){
					xia*=j;
				}
				o[3]=shang/xia;
			}else {
				o[i]=o[i-1]*(n-i+1)%mod/(i)%mod;
			}
		}
		for(int i=3;i<=n;++i){
			x+=o[i];
		}
		printf("%d",x);
	}else {
		dfs(1);
		printf("%d",ans);
	}
/*
5
1 2 3 4 5
*/
	return 0;
}