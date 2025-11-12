#include<bits/stdc++.h>
using namespace std;

int main () {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,ans=0;
	cin>>n>>m;
	string s;
	cin>>s;
	for(long long i=1;i<=n;i++){
		long long y;
		cin>>y;
		ans+=y;
	}
	cout<<ans*ans*ans%998244353;
	return 0;
}