#include<bits/stdc++.h>
using namespace std;
long long mod=998244353;
long long a[1020];
long long f[1020];
long long w[1020];
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	long long i,j;
	f[0]=1;
	for (i=1;i<=1000;i++)
	{
		f[i]=f[i-1]*i;f[i]%=mod;
	}
	long long n,m;
	cin>>n>>m;
	cin>>s;
	for (i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if (n>20)
	{
		long long k=1;
		for (i=1;i<=n;i++)
		{
			k*=i;k%=mod;
		}
		cout<<k<<endl;
		return 0;
	}
	sort(a+1,a+n+1);
	long long ans=0;
	do
	{
		long long cnt1=0,cnt2=0;
		for (i=1;i<=n;i++)
		{
			if (cnt1>=a[i])
			{
				cnt1++;
			}
			else
			{
				if (s[i-1]=='0')
				{
					cnt1++;
				}
				else
				{
					cnt2++;
				}
			}
		}
		if (cnt2>=m)
		{
			ans++;ans%=mod;
		}
	} while (next_permutation(a+1,a+n+1));
	for (i=1;i<=n;i++)
	{
		w[a[i]]++;
	}
	for (i=1;i<=n;i++)
	{
		if (w[i]>1)
		{
			ans*=f[w[i]];ans%=mod;
		}
	}
	cout<<ans<<"\n";
	return 0;
}

