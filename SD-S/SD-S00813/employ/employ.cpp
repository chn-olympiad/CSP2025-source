#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const int N=505;
const ll mod=998244353;
int n,m,c[N];
string s;
ll ans=1;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(ll i=n;i>=1;i--){
		ans=(ans*i)%mod;
	}
	cout<<ans;
	return 0;
}
