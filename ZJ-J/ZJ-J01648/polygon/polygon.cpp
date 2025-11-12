#include<bits/stdc++.h>
#define mod 998244353
#define ini 499122177
using namespace std;
int n,a[50005],sum[5005],ans;
void dfs(int x,int summ,int o){
	if(summ+sum[o-1]-sum[x-1]<=a[o])return ;
	if(x==o){
		if(summ>a[o])ans++,ans%=mod;
		return ;
	}
	dfs(x+1,summ+a[x],o);
	dfs(x+1,summ,o);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=3;i<=n;i++){
		dfs(1,0,i);
	}
	cout<<ans;
}
/*
我是奶龙！
我才是奶龙！
我才是萘陇！ 
我才是艿拢！ 
*/
