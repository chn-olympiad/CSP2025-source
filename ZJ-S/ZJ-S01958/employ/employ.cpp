#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n,m,sum=1;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		sum*=i;
		sum%=mod;
	}
	cout<<sum;
	return 0;
}
