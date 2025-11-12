#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
bool b[500005];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,z=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k)
		{
			z++;
			b[i]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!b[i])
		{
			int h=0;
			for(int j=i;i<=n;j++)
			{
				if(b[j])
				{
					break;
				}
				h^=a[j];
				b[j]=1;
				if(h==k)
				{
					z++;
					break;
				}
			}
		}
	}
	cout<<z;
	return 0;
}
