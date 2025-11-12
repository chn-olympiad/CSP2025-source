#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=550;
const unsigned long long mod=998244353;
ll n,m;
string s;
struct node
{
	ll id,val;
} x[N];
inline ll read()
{
	ll k=0;
	char c=getchar();
	while(c<48 || c>57) c=getchar();
	while(c>=48 && c<=57) k=(k<<3ll)+(k<<1ll)+c-48ll,c=getchar();
	return k;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	cin>>s;
	for(ll i=1;i<=n;i++) x[i].val=read(),x[i].id=i;
		ll ans=1;
		for(ll i=2;i<n;i++) (ans*=i)%=mod;
		printf("%lld",ans);
		return 0;
}
/*

*/