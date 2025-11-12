#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Mod=998244353;
int n;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	ll ans=1;
	for(int i=1;i<=n;i++)
		ans=(ll)ans*i%Mod;
	cout<<ans<<"\n";
	return 0;
}