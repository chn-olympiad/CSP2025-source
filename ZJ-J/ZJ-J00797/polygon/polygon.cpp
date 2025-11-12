#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll M=998244353;
ll n,a[5001],answ=0;

ll ksm(ll x,ll y){
	ll ans=1;
	while(y){
		if(y&1){
			ans=x*ans%M;
		}
		x=x*x%M;
		y>>=1;
	}
	return ans;
}

void dfs(ll cs,ll mx,ll sum){
	if(cs>n){
		if(sum>mx*2ll)answ++;
		return;
	}else{
		dfs(cs+1ll,max(mx,a[cs]),sum+a[cs]);
		dfs(cs+1ll,mx,sum);
		return;
	}
	return;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(a[n]==1){
		int cut=(n+1)*n/2;
		cout<<(M+ksm(2,n)-cut)%M;
	}else{
		dfs(1,0,0);
		cout<<answ;
	}
	return 0;
}