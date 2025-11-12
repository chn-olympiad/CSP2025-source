#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n,m;
long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		ans=(ans*i)%mod;
	cout<<ans;
 	return 0;
}
