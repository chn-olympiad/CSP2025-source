#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 2000006
ll n,m,a[505],n1,mod=998244353,ans=1,sum,mmin=0x3f3f3f3f,cnt=1;
string s;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	n1=n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]) mmin=min(mmin,a[i]);
		if(a[i]==0){
			n1--;
		}
	}
	for(ll i=2;i<=n-mmin-1;i++) ans=(ans*i%mod)%mod;
	if(n1<m) cout<<0;
	else cout<<(ans*(n1-m)%mod)%mod;
	return 0;
}
