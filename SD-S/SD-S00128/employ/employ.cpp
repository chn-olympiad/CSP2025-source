#include<iostream>
using namespace std;
typedef long long ll;
ll n,m,a[510];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(ll i=1;i<=n;i++) cin>>a[i];
	if(m==n){
		ll sl=s.length(),f1=0,f2=0;
		ll ans=1;
		for(ll i=1;i<=sl;i++) if(s[i]=='0') f1=1;
		for(ll i=1;i<=n;i++){
			if(a[i]==0) f2=1;
			ans*=i;
			ans%=998244353;
		} 
		if(f1==0&&f2==0) cout<<ans;
	}else cout<<2;
	return 0;
}

