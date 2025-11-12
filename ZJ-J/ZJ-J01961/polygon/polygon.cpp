#include<bits/stdc++.h>
using namespace std;
const int N=5010;
const long long mod=998244353ll;
int n,a[N],sum[N];
long long ans;
void dfs(int x,int num,int mx,int sum){
	if(x>n){
		if(num<3||sum<=mx*2)return;
		ans++,ans%=mod;
		return;
	}dfs(x+1,num+1,a[x],sum+a[x]),dfs(x+1,num,mx,sum);
}int main(){
	cin>>n;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(n<=20){
		sort(a+1,a+n+1);
		dfs(1,0,0,0);
		cout<<ans;
		return 0;
	}for(int i=3;i<=n;i++){
		long long add=1ll;
		for(long long j=1ll*n;j>1ll*n-1ll*i;j--)add*=j,add%=mod;
		for(long long j=1ll;j<=1ll*i;j++)add/=j;
		ans+=add,ans%=mod;
	}cout<<ans;
	return 0;
}
