#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int main(){
	unsigned long long int ans=1;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n;
	cin>>n;
	for(int i=2;i<=n;i++){
		ans=(ans*i)%mod;
	}
	cout<<ans<<endl;
	return 0;
}
