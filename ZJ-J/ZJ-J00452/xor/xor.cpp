#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
using namespace std;
const ll N=5e5+10;
ll n,k,s[N],a[N],cnt;
//vector<pii>fa[1010];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	ll tj=0,zsl=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>tj)
		{
			tj=a[i];
			zsl=1;
		}
		else if(a[i]==tj)
		{
			zsl++;
		}
		s[i]=s[i-1]^a[i];
	}
	if(tj<=1)
	{
		if(zsl==n)
		{
			if(tj==1)
			{
				if(k==0)
				{
					cout<<n/2;
					return 0;
				}
				else
				{
					cout<<n;
				}
			}
			else
			{
				if(k==1)
				{
					cout<<0;
					return 0;
				}
				else
				{
					cout<<n;
					return 0;
				}
			}
		}
		else
		{
			if(k==1)
			{
				cout<<zsl;
				return 0;
			}
			else
			{
				ll res=0,i=1;
				while(i<=n)
				{
					if(a[i]==1)
					{
						res++;
						i+=2;
					}
					else
					{
						res++;
						i++;
					}
				}
				cout<<res;
				return 0;
			}
		}
	}
	if(tj<k)
	{
		cout<<0;
	}
	ll ans=0;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=i;j<=n;j++)
//		{
//			if(s[j]^s[i-1]==k)
//				fa[i].push_back(j);
//				fa[i].push_back(j);
//			}
//		}
//	}
	return 0;
}
