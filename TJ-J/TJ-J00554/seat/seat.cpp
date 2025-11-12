#include<bits/stdc++.h>

using namespace std;
int n,m,a[101],b,ans;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	ans=a[1];
	for(int i=1;i<=n*m;i++)
	{
		b=i;
		for(int j=i;j<=n*m;j++)
		{
			if(a[j]>a[b])
			{
				b=j;
			}
		}
		swap(a[i],a[b]);
	}
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==ans)
		{
			cout<<i/n+1<<' '<<i%n;
			break;
		}
	}
	return 0;
}
