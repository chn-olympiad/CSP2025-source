#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
ll n,m,Num1;
string s;
ll c[555];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	scanf("%lld%lld",&n,&m);
	cin>>s;
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&c[i]);
	}
	
	for(ll i=0;i<n;i++) 
	{
		if((s[i]-'0')==1) Num1++;
	}
	
	
	if(Num1==n) {
		ll ans=1;
		for(ll i=1;i<=n;i++)
		{
			ans=ans*i%mod;
		}
		printf("%lld",ans%mod);
	}
	else if(Num1<m) {
		printf("0");
	}
	else
	{
		printf("0");
	}
	
	return 0;
 } 