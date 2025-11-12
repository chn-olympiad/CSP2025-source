#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=600;
ll n,m,c[N];
ll mod=998244353;
string s;
void solve(){
	ll x=1;
	for(int i=1;i<=n;i++){
		x*=i;
		x%=mod;
	}
	cout<<x;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	ll u=1;
	for(int i=0;i<n;i++)
		if(s[i]!='1') u=0;
	if(u==1){
		solve();
		return 0;
	}
	return 0;
}