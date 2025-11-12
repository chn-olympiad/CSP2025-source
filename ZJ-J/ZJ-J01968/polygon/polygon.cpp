#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e3+10,MOD=998244353;
ll n;
ll a[N],c[N],ans;
bool vis[N];
bool flag;
struct node{
	ll mmax;
	ll sum;
	ll bian;
	bool vis[N];
};
void dfs(ll d){
	if(d>n)return;
	ll maxx=0,sum=0;
	for(ll i=1;i<=d;i++){
		cout<<c[i]<<" ";
		sum+=c[i];
		maxx=max(maxx,c[i]);
	}
	cout<<"\n";
	if(sum>2*maxx)ans++;
	for(ll i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		c[i]=a[i];
		dfs(d+1);
		vis[i]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag=1;
	}
	if(flag==0){
		for(ll i=3;i<=n;i++){
			ll l=1;
			for(ll j=1;j<=i;j++)l=l*(n-j+1)/j%MOD;
			ans=(ans+l)%MOD;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	dfs(0);
	cout<<ans;
	return 0;
}
