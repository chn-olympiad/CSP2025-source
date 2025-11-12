#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353
ll n,m;
string s;
ll a[505];
ll q[505],qi;
bool used[505];
ll ans=0;
void dfs(ll xi){
	if(xi==n){
		ll sum=0,io=0;
		for(ll i=1;i<=n;i++){
			if(a[q[i]]>io){
				if(s[i-1]=='0'){
					io++;
				}
				else{
					sum++;
					if(sum>=m) break;
				}
			}
			else{
				io++;
			}
		}
		if(sum>=m){
			ans=(ans+1)%MOD;
		}
	}
	for(ll i=1;i<=n;i++){
		if(!used[i]){
			q[++qi]=i;
			used[i]=true;
			dfs(xi+1);
			used[i]=false;
			--qi;
		}
	}
}
inline ll jc(ll x){
	ll ans=1;
	for(ll i=1;i<=x;i++){
		ans=(ans*i)%MOD;
	}
	return ans;
}
inline ll fpow(ll x,ll y){
	ll ans=1;
	while(y){
		if(y&1) ans=(ans*x)%MOD;
		y>>=1;
		x=(x*x)%MOD;
	}
	return ans;
}
ll nnn0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	ll fl=0;
	for(ll i=0;i<s.size();i++){
		if(s[i]=='0'){
			fl++;
		}
	}
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			nnn0++;
		}
	}
	if(nnn0+m>n){
		cout<<0;
		return 0;
	}
	if(!fl){
		cout<<jc(n);
		return 0;
	}
	dfs(0);
	cout<<ans;
	return 0;
}
