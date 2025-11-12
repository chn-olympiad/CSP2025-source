#include<bits/stdc++.h>
using namespace std;
long long n,k,v,ans;
int b[500005],a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>v;
		a[i]=(a[i-1]^v);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if((a[j]^a[i-1])==k)
			{
				ans++;
				i=j;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}

