#include <bits/stdc++.h>
using namespace std;
int n,a[5005];
long long ans,cnt,md=998244353;
bool cmp(int x,int y){
	return x>y;
}
void dfs(int x,int sum,int k){
	if (sum==a[k]){
		cnt+=x-k-1;
		cnt%=md;
		return;
	}
	else if (sum>a[k]){
		cnt+=x-k;
		cnt%=md;
		return;
	}
	for (int i=x-1;i>k;i--){
		int num=sum+a[i];
		dfs(i,num,k);
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n,cmp);
	for (int i=1;i<=n;i++){
		cnt=0;
		dfs(n+1,0,i);
		ans=(ans+cnt)%md;
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
}
