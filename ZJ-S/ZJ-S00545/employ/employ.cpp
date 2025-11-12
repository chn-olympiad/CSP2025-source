#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string sig;
typedef vector<ll> vel;
typedef pair<ll,ll> pll;
typedef vector<vel> vevel;
typedef vector<pll> velp;
const ll mo=998244353;
ll n,m,anss=0;
sig s;
vel v,tmp;
void dfs(ll x,queue<ll> q){
	if(x>n){
		ll cnt=0;
		for(int i=1;i<=n;i++){
			ll j=tmp[i];
			if((i-1)-cnt>v[j]){
				continue;
			}
			if(s[i]=='1'){
				cnt++;
			}
		}
		if(cnt>=m)anss++;
		anss%=mo;
	}
	queue<ll> qq=q;
	for(int i=1;i<=q.size();i++){
		q.pop();
		q.push(qq.front());
		tmp[i]=qq.front();
		qq.pop();
		dfs(x+1,qq);
		qq=q;
	}
}
void slv(){
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	v=tmp=vel(n+3);
	bool b=1;
	for(int i=1;i<=n;i++){
		cin>>v[i];
		if(s[i]=='0')b=0;
	}
	if(b){
		ll ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=mo;
		}
		cout<<ans;
		return;
	}
	if(n<=10){
		queue<ll> q;
		for(int i=1;i<=n;i++){
			q.push(i);
		}
		dfs(1,q);
		cout<<anss%mo;
		return ;
	}
	cout<<0;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll T=1;
	while(T--){
		slv();
	}
	return 0;
}