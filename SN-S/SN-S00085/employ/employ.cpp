#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FI(x) freopen(x".in","r",stdin)
#define FO(x) freopen(x".out","w",stdout)
int n,m,a[100000],sum=1;
string s;

signed main(){
	FI("employ");
	FO("employ");
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=2;i<=n;i++){
		sum*=i;
		sum%=998244353;
	}
	cout<<sum;
	return 0;
}

