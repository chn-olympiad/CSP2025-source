#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+10,MOD=998244353;
ll a[N],n,ans,b;
bool vis[N],can;
void bfs(ll x,ll ni,ll sum,ll maxn){
	if(ni>b){
		if(sum>maxn*2) ans++,ans%=MOD;
		else can=0;
		return ;
	}
	for(int i=x;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			bfs(i+1,ni+1,(sum+a[i])%MOD,max(maxn,a[i]));
			vis[i]=0;
		}
		if(!can){can=1;return ;}
	}
}
int main(){
	freopen("polygon.in","r",stdin); freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(ll i=3;i<=n;i++){
		memset(vis,0,sizeof vis);
		b=i;
		bfs(1,1,0,0);
	}
	cout<<ans;
	return 0;
}