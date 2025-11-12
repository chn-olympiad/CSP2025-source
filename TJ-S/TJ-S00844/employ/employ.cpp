#include <bits/stdc++.h>
using namespace std;
int c[505];
int a[505]
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	
	for (int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=i;j++)
		{
			if(a[j]==0) 
			{
				a[i]++;
				if(a[i]>=c[i])
				{
					c[i]=0;
					
				}
			}
		}
	}
	int ans=n;
	for (int i=1;i<=n;i++)
	{
		if(c[i]==0) ans--;
	}
	cout<<ans*ans;
	return 0;
}
