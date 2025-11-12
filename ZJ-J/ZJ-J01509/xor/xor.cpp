#include <bits/stdc++.h>
using namespace std;
#define For(i,j,k) for(int i=j;i<=k;i++)
#define dFor(i,j,k) for(int i=j;i>=k;i--)
#define ll long long

ll n,k;
ll a[500005];

void p() // quan shi 1 he 0
{
	a[n+1]=!(a[n]);
	if(k == 1)
	{
		ll cnt=0;
		For(i,1,n)
		{
			if(a[i] == 1)
			{
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	else 
	{
		ll cnt=0;
		ll ans=0;
		For(i,1,n+1)
		{
			if(a[i]==a[i-1])
			{
				cnt++;
			}
			else
			{
				if(a[i-1]==0)
				{
					ans+=cnt;
				}
				else ans+=(cnt/2);
				cnt=1;
			}
		}
		cout<<ans<<endl;
	}	
}

void z()
{
	ll ans=0;
	For(i,1,n-1)
	{
		ll tot=0;
		ll x=a[i];
		ll j=i+1;
		while(j<=n+1)
		{
			if(x==k)
			{
				tot++;
				x = a[j];
			}
			else
			{
				x = x ^ a[j];
			}
			j++;

		}
		ans=max(ans,tot);
	}
	cout<<ans<<endl;
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	For(i,1,n)
	{
		cin>>a[i];
	}
	if(k<=1)
	{
		p();
	}
	else 
	{
		z();
	}
	return 0;
}
