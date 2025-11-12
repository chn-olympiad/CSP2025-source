#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m;
string s;
int a[510];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long fac=1;
	for(int i=1;i<=n;i++){
		fac=1ll*fac*i%mod;
	}
	cout<<fac%mod;
	return 0;
}
