#include <bits/stdc++.h>

using namespace std;
long long a[1000000],b[1000000],n,k,cnt,maxxl=-10,maxxr=-10;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	int flag=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==1) cnt++;
		if(a[i]==0)
		{
			flag=0;
		}
	}
	if(flag==1&&cnt%2==0&&k==0)
	{
		cout<<cnt;
		return 0;
	}
	else if(cnt%2==1) 
	{
		cnt-=1;
		cout<<cnt;
		return 0;
	}
	cnt=0;
	for(int l=1;l<=n;l++)
	{
		for(int r=l;r<=n;r++)
		{
			for(int i=l;i<=r;i++)
			{
				cnt^=i;
			}
			if(cnt==k)
			{
				cnt=0;
				maxxl=l;
				maxxr=r;
			}
		}
	}
	if(maxxr==maxxl) cout<<1;
	else 
	{
		int z=maxxr-maxxl;
		cout<<z;
    }
	
	
	return 0;
}
