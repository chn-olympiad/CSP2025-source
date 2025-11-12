#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string sig;
typedef vector<ll> vel;
typedef pair<ll,ll> pll;
typedef vector<pll> velp;
typedef vector<vel> vevel;
void slv(){
	sig s;
	cin>>s;
	ll n=s.size();
	s=' '+s;
	vel v(13);
	for(int i=1;i<=n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			v[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(v[i]--){
			cout<<i;
		}
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll T=1;
	while(T--){
		slv();
	}
	return 0;
}