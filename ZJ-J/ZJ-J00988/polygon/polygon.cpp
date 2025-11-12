#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],ans;
bool cmp(long long x,long long y){return x>y;}
void dfs(long long st,long long sum,long long mx,long long b){
	if(b>=3 and sum>mx*2) {
		ans=(ans+(1<<(n-st)))%998244353;
		return ;
	}
	if(st>n){
		return ;
	}
	dfs(st+1,sum+a[st+1],max(mx,a[st+1]),b+1);
	dfs(st+1,sum,mx,b);
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,cmp);
	dfs(1,a[1],a[1],1);
	dfs(1,0,0,0);
	cout<<(ans)%998244353;
	return 0;
}
