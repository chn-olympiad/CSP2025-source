#include<iostream>
#define int long long
using namespace std;
int n,m,a[505];
const int mod=998244353;
string s;
signed main(){
	freopen("empoly.in","r",stdin);
	freopen("empoly.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=1;
	for(int i=2;i<=n;i++){
		ans*=i;
		ans%=mod;
	}
	cout<<ans;
	return 0;
} 
