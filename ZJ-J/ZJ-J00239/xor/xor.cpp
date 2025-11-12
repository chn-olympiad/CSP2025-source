#include<bits/stdc++.h>
using namespace std;
long long n,k;
unsigned long long maxn=0,minn=4e18;
long long ans=0;
unsigned long long a[500005],sa[500005];
bool d[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//xor:^
//	cout<<(3^4^2^1^(3^4));
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{	
		cin>>a[i];
		sa[i]=(sa[i-1]^a[i]);
		maxn=max(maxn,a[i]);
		minn=min(minn,a[i]);
	}
	if(maxn==1 && minn==1 && k==0)
	{
		cout<<n/2<<endl;
		return 0;
	}
	if(maxn==1 && minn==0 && k<=1)
	{
		if(k==1)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1) ans++;
			}
			cout<<ans<<endl;
			return 0;
		}
		else 
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==0) ans++;
				if(a[i]==1 && a[i+1]==1)
				{
					i++;
					ans++;
				}
			}
			cout<<ans<<endl;
			return 0;
		}
	}
	long long cnt=0;
	long long x=n;
	for(int q=1;q<=x;q++)
	{
		cnt=0;
		for(int i=q;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
//				cout<<q<<" "<<i<<" "<<j<<" "<<(sa[j]^sa[i-1])<<endl;
				if((sa[j]^sa[i-1])==k)
				{
					if(x==n) x=j;
//					cout<<q<<" "<<i<<" "<<j<<endl;
					cnt++;
					i=j+1;
				}
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
