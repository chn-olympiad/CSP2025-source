#include<bits/stdc++.h>
using namespace std;
bool vis[5005];
int n,a[5005],ans=0;
void dfs(int x,int y,int k){
	if(x>=y){
		int sum=0;
		for(int i=1;i<y;i++)
			if(vis[i])
				sum+=a[i];
		if(sum>k)
			ans=(ans+1)%988244353;
		return;
	}
	vis[x]=1;
	dfs(x+1,y,k);
	vis[x]=0;
	dfs(x+1,y,k);
}
int p(int n){
	int a=1;
	for(int i=1;i<=n;i++)
		a=a*i%988244353;
	return a;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	if(a[n]==1){
		for(int i=3;i<=n;i++)
			ans=(ans+p(n)/(p(i)*p(n-i)))%988244353;
		printf("%d\n",ans);
		return 0;
	}
	for(int i=n;i>=3;i--){
		int sum=0;
		for(int j=1;j<i;j++)
			sum+=a[j];
		if(sum>a[i]){
			if(sum-a[i-1]<=a[i])
				dfs(1,i-1,a[i]-a[i-1]);
			else
				dfs(1,i,a[i]);
		}
	}
	printf("%d\n",ans);
	return 0;
}
