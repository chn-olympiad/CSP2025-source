#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N=505;
const int mod=998244353;
string s;
int n,m;
int c[N];
int ans=1;

signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	
	for(int i=2;i<=n;i++){
		ans=(ans*i)%mod;
	}
	
	cout<<ans<<"\n";
	return 0;
}
