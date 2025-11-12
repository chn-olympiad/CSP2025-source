#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,a[505];
	string s;
	cin>>n>>s;
	for(long long i=1;i<=n;i++)cin>>a[i];
	
	long long ans=1;
	long long mod=998244353;
	for(long long i=1;i<=n;i++){
		ans*=i;
		ans%=mod;
	}
	cout<<ans;
	return 0;
}
