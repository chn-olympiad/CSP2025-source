#include<bits/stdc++.h>
using namespace std;
const int mod=998244535;
long long n,a[505],ans=1,m;
string s;
int na[505],nc[505],cnt=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	for(int i=0;i<n;i++) na[i]=s[i]-'0';
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	sort(a,a+n);
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=mod;
	}
	cout<<ans%mod;
	return 0;
}