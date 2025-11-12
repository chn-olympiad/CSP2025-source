#include<bits/stdc++.h>
using namespace std;
int n,a[5001],i,j,s=0;
long long ans=0;
void dfs(int fir,int num,int maxn,int sum){
	if(num==j&&sum>2*maxn){
		ans++;
		return;
	}
	if(num!=j) for(int r=fir+1;r<=n-j+num+1;r++){
		dfs(r,num+1,a[r],sum+a[r]);
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int t=1;t<=n;t++){
		scanf("%d",&a[t]);
		if(a[t]!=1) s=1;
	}
	sort(1+a,1+a+n);
	if(s==0){
		int q=n-2;
		while(q!=0){
			ans+=q;
			q--;
		}
	}
	else{
		for(i=1;i<=n-2;i++)
		for(j=3;j<=n-i+1;j++){
			dfs(i,1,a[i],a[i]);
		}
	}
	printf("%lld",ans%998244353);
	return 0;
}