#include<bits/stdc++.h>
using namespace std;
int n,ans;
const int nn=5010,mod=998244353;
int a[nn],b[nn];
void youhua(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void dfs(int x,int sum,int maxn){
	if(x==n+1){
		if(sum>maxn*2)
		{
			ans=(ans+1)%mod;
		}
		return;
	}
	if(sum+b[n]-b[x-1]<=maxn*2)	
		return;
	dfs(x+1,sum+a[x],max(maxn,a[x]));
	dfs(x+1,sum,maxn);
}
int main(){
	youhua();
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]+a[i];
	}
	dfs(1,0,0);
	cout<<ans%mod;
	return 0;
}
//in.4超时，但是没有停止工作 



//rp++ 相信自己 
