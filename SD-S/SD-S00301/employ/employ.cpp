#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define ll long long
using namespace std;
const ll MOD=998244353;
const ll N=505;
ll n,m,c[N];
vector<ll> p;
string s;
void solve1_2(){
	for(ll i=1;i<=n;i++) p.push_back(i);
	ll cnt,ans=0,prh;
	do{
		cnt=prh=0;
		for(ll i=1;i<=n;i++){
			if(s[i]=='0') prh++;
			else{
				if(prh>=c[p[i-1]]) prh++;
				else cnt++;
			}
		}
		if(cnt>=m) ans++;
		if(ans>=MOD) ans-=MOD;
	}while(next_permutation(p.begin(),p.end()));
	cout<<ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;s=' '+s;
	for(ll i=1;i<=n;i++) cin>>c[i];
	solve1_2();
	return 0;
}

