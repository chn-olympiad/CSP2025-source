#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=5005;
const int Mod=998244353;
ll n,ans,a[MAXN];
void dfs(ll cnt,ll sum,ll Max,ll now){
	if(now>n){
		if(cnt>=3&&sum>Max*2) ans=(ans+1)%Mod;
		return;
	}
	for(int i=0;i<=1;i++){
		dfs(cnt+i,sum+i*a[now],max(Max,i*a[now]),now+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		flag=(flag&(a[i]==1));
	}
	if(flag){
		ll p=1;
		for(int i=1;i<=n;i++){
			p*=2;
			p%=Mod;
		}
		cout<<((p-1-n-(n-1)*n/2)%Mod+Mod)%Mod;
	}
	else{
		dfs(0,0,0,1);
		cout<<ans;
	}
	return 0;
}
