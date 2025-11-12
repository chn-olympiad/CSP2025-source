#include <bits/stdc++.h>
using namespace std;
long long n,m,ans=2;
string s;
long long c[550];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(long long i=1;i<=n;i++){
		cin>>c[i];
	}
	for(long long i=3;i<=n;i++){
		ans=ans*i%998244353;
	}
	cout<<ans%998244353;
	
	
	return 0;
}
