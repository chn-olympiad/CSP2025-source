#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],c[500005],ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		c[i]=c[i-1]^a[i];
	}
	for(int l=1;l<=n;l++)
	{
		for(int r=l;r<=n;r++)
		{
			if((c[r]^c[l-1])==k)
			{
				ans++;
				l=r;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}

