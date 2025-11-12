#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const int N=5e5+10;

ll n,k;
ll a[N];
ll as,s,p;
ll xr[N];
ll l,r;
bool f;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)f=1;
	}
	
	if(k==0&&!f)
	{
		cout<<n/2;
	}
	else
	{
		xr[1]=a[1];
		for(int i=2;i<=n;i++)
		{
			xr[i]=a[i]^xr[i-1];
		}
		
		for(int i=1;i<=n;i++)
		{
			if(a[i]==k)i++,as++;
			for(int l=1;i+l-1<=n;l++)
			{
				if(ll(xr[i+l-1]^xr[i-1])==k)
				{
					as++;
	//				cout<<i<<' '<<l+i-1<<'\n';
					i=l+i;
				}
			}
		}
		
		cout<<as;
	}
	
	                             
	return 0;
}
//fc xor.out xor.ans