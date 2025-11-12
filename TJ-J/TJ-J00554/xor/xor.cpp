#include<bits/stdc++.h>

using namespace std;
int n,k,a[100001],ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int b=i;b<=j;b++)
			{
				a[b+1]=a[b]^a[b+1];
			}
			if(a[j]==k)
			{
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
