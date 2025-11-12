#include<bits/stdc++.h>
using namespace std;
long long n,a[10000],sum,a1[10000],ad[10000];
void dfs(long long m,long long sum1,long long mx1,long long mi,long long i1){
	if(sum1>2*mx1&&mi==m){
		sum++;
	} 
	if(mi>m) return;
	for(long long i=i1;i<=n;i++){
		a1[mi]=a[i];
		dfs(m,sum1+a[i],max(mx1,a[i]),mi+1,i+1);
		a1[mi]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=3;i<=n+1;i++){
		dfs(i,0,0,1,1);
	}
	sum%=998244353; 
	printf("%lld",sum);
	return 0;
}
