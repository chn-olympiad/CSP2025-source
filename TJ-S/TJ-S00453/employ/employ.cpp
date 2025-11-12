#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long ans=1;
	for(long long i=1;i<=n;i++){
		ans=ans*i;
	}
	cout<<ans%998244353;
	return 0;
}
