#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int n,m;
string s;
int c[505];
long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		ans=((ans%mod)*(i%mod))%mod;
	}
	cout<<ans;
	return 0;
}
