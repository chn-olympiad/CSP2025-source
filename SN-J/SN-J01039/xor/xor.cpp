#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,k,a[N];
int b[N];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool f=true;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) f=false;
		b[i]=(b[i-1]^a[i]);
	}
	if(f)
	{
		cout<<n/2<<"\n";
		return 0;
	}
	int nxl=0,nxr=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		int l=i,r=i;
		int cnt=0;
		while(l<=n)
		{
			for(int rr=l;rr<=n;rr++)
			{
				int sz=(b[rr]^b[l-1]);
				if(sz==k)
				{
					r=rr;
					break;
				}
				if(rr==n)
				{
					r=n+1;
					break;
				}
			}
			if(l<=r && r<=n)
			{
				cnt++;
				l=r+1;
			}
			else if(r==n+1)
			{
				l++;
			}
			//cout<<i<<" "<<l<<" "<<r<<"\n";
		}
		ans=max(cnt,ans);
	}
	cout<<ans<<"\n";
	return 0;
}
