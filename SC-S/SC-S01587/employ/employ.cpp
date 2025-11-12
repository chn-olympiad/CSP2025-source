#include<bits/stdc++.h>
using namespace std;
long long n,ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	for(int i=1;i<=n;i++){
		ans%=998244353;
		ans*=(i%998244353)%998244353;
	}
	cout<<ans;
	return 0;
} 