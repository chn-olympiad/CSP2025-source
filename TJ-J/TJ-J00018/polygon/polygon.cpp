#include<cstdio>
#include<algorithm>
int n;
int a[5012];
int C=0;
int mod(long long x){
	return x%998244353;
}
void dfs(int m,long long s,long long c,int t){
	if(m==n){
		if(s>2*t&&c>=3){
			C=mod(C+1);
		}
		return;
	}
	dfs(m+1,s+a[m+1],c+1,a[m+1]);
	
	dfs(m+1,s,c,t);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	std::sort(&a[1],&a[n+1]);
	dfs(0,0,0,0);
	printf("%d\n",C);
	return 0;
}
