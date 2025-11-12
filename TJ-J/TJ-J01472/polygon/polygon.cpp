#include <bits/stdc++.h>
using namespace std;
int const N=10000;
long long n,a[N],ans=0;
void dfs(long long sum,int m,int j){
	if(sum>(m*2)){
		ans++;
		ans=ans%998244353;
	}
	for(int i=j;i<=n;i++){
		if(a[i]>m)m=a[i];
		dfs(sum+a[i],m,i+1);
	}
	return ;
}
int main(){
	long long sum=0;
	int m=0,j=1;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	dfs(sum,m,j);
	printf("%lld\n",ans);
	return 0;
}
