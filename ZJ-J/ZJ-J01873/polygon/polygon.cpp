#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod=998244353;
ll n,maxn,sum,ans;
ll a[5005];
ll jc(ll k){
	ll res=1;
	for(int i=1;i<=k;i++) res*=i,res%=mod;
	return res;
}ll p(ll x,ll y){
	ll L=y+1,R=x,res=1,_res=1,f=0;
	for(ll i=1;i<=y;i++) _res*=i;
//	cout<<_res<<endl;
	for(ll i=L;i<=R;i++){
		if(i%_res==0&&!f) i/=_res,f=1;
		res*=i;
		res%=mod;
	}
	return res;
}
void dfs(ll x,ll y,ll s,ll mx,ll f){
	if((n-x+1)+y<3) return;
	if(s>mx*2&&f) ans++,ans%=mod;
//	if(s<=mx*2&&!f&&y>=3) return;
	if(x==n+1) return;
	dfs(x+1,y+1,s+a[x],a[x],1);
	dfs(x+1,y,s,mx,0);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
//	cout<<p(20,3)<<endl;
	for(ll i=1;i<=n;i++) cin>>a[i],maxn=max(maxn,a[i]),sum+=a[i];
//	if(maxn==1&&n>27){
//		ll res=0;
//		for(int i=3;i<=n;i++)
//			res+=p(n,i),res%=mod;
//		cout<<res;
//		return 0;
//	}else if(maxn==1){
//		
//	}
	sort(a+1,a+n+1);
	dfs(1ll,0ll,0ll,0ll,0ll);
	cout<<ans;
	return 0;
}
/*
20
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20

20
75 28 15 26 12 8 90 42 90 43 14 26 84 83 14 35 98 38 37 1

20
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

28
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

1048365

5
1 1 1 1 1
1 2 3
1 2 4
1 2 5
1 3 4
1 3 5
1 4 5
2 3 4
2 3 5
2 4 5
3 4 5
1 2 3 4
1 2 3 5
1 2 4 5
1 3 4 5
2 3 4 5
1 2 3 4 5

5!/2!/(5-2)!

转为所有可能减去不合法的数量 

100+100+30+40
*/
