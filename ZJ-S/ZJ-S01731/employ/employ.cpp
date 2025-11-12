#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
typedef long long ll;
const ll mod=998244353;
int a[maxn],c[maxn],t[maxn];
ll fac[510];
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m,sum=0;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		a[i]=int(s[i-1]-'0');
		sum+=a[i];
	}
	fac[0]=1;
	for(int i=1;i<=500;i++)
		fac[i]=(fac[i-1]%mod*i%mod)%mod;
	if(m==n)
	{
		int flag=1;
		for(int i=1;i<=n;i++)
			if(c[i]==0)
				flag=0;
		if(flag==0||sum>0)
			cout<<0<<endl;
		else
			cout<<fac[n]<<endl;
		return 0;
	}
	if(m==1)
	{
		sort(c+1,c+n+1);
		ll pos=0,alr=0;
		ll ans=1,flag=1;
		for(int i=1;i<=n;i++)
			t[i]=a[i]+t[i-1];
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				while(c[pos+1]<=i-1&&pos+1<=n)
					pos++;
				if(pos<=alr)
				{
					flag=0;
					break;
				}
				ans=ans%mod*(pos-alr)%mod;
				ans%=mod;
				alr++;
			}
		}
		if(flag==0)
		{
			cout<<fac[n]%mod<<endl;
		}
		else
		{
			ans=ans%mod*fac[sum]%mod;
			ans%=mod;
			ll op=((fac[n]%mod-ans%mod)%mod+mod)%mod;
			cout<<op<<endl;
		}
		return 0;
	}
//	for(int i=1;i<=n;i++)
//	{
//		
//	}
	return 0;
}


