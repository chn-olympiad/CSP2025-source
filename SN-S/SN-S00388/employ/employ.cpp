//SN-S00388
#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,m,a[505];
long long ans=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		ans=ans*i%mod;
	}
	ans=(ans+mod)%mod;
	cout<<ans;
	return 0;
}
