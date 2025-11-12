#include<bits/stdc++.h>
#define int long long
using namespace std;
long long a[500005],t[500005];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		t[i]=t[i-1]^a[i];
	}
	int r=n,l=r-1,ans=0;
	while(r>=1)
	{
		int x=t[r]^t[l];
		if(x==k)
		{
			ans++;
			r=l;
			l=r-1;
		}
		else
		{
			if(l>0)
			{
				l--;
			}
			else
			{
				r--;
			}
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
