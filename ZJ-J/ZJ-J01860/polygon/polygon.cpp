#include<bits/stdc++.h>
using namespace std;
int a[5100];
const int mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
 	freopen("polygon.out","w",stdout);
 	int n;
 	cin>>n;
 	for(int i=1;i<=n;i++){
 		cin>>a[i];
	}
	long long int ans=0;
	for(int i=3;i<=n;i++){
		int sma=1;
		for(int o=n;o>=i+1;o--)sma=sma*o%mod;
		ans=(ans+sma)%mod;
	}
	cout<<ans%mod;
	return 0;
}

