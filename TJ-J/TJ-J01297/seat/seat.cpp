#include <bits/stdc++.h>
using namespace std;
int a[11];
int main(void)
{
	freopen("seat.in","r",stdin);
	int n,m,k,s;
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	{
		cin>>a[i];
		s=a[1];
	}
	for(i=1;i<=n*m;i++)
	{
		k=i;
		for(j=1;j<=n*m;j++)
		{
			if(a[k]>a[j])
				swap(a[k],a[j]);
		}
	}
	for(i=1;i<=n*m;i++)
	{
		cout<<a[i];
	}
	freopen("seat.out","w",stdout);
	return 0;
}
