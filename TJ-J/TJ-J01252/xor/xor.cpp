#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];
int b[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	b[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		b[i]=b[i-1]^a[i];
	}
	int ans=0;
	for(int i=1,j=1;i<=n;i++)
	{
		while(j<=n&&b[j]^b[i-1]!=k)
		{
			j++;
		}
		if(b[j]^b[i-1]==k)
		{
			ans++;
			i=j;
		}
		else
		{
			j=i;
		}
		j++;
	}
	cout<<ans;
	return 0;
}

