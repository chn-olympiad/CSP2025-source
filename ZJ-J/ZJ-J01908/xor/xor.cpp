#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int b[500005];
int ans=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i]^b[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==k)
		{
			ans++;
			for(int j=i+1;j<=n;j++)
			{
				b[j]=b[j]^b[i];
			}
		}
	}
	cout<<ans;
	return 0;
}
