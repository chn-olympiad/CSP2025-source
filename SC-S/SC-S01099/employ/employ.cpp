#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
const int P=998244353;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n;
	cin>>n;
	int ans=1;
	for(int i=1;i<=n;i++){
		ans=(ans*i)%P;
	}
	cout<<ans<<endl;
	return 0;
}
