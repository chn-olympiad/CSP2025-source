#include <bits/stdc++.h>
using namespace std;
long long b[500],a[20][20],n,m,f,k=1,i,j;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	k=0;
	for(int i=1;i<=m*n;i++)
	{
		cin>>b[i];
	}
	f=b[1];
	sort(b+1,b+1+n*m);
	reverse(b+1,b+1+n*m);
	for(i=1;i<=m;i++)
	{
		if(i%2==0)
		{
			for(j=n;j>=1;j--)
			{
				k++;
				if(b[k]==f)
				{
					cout<<i<<" "<<j;
					return 0;
				}
				a[j][i]=b[k];
			}
		}
		else
		{
  			for(j=1;j<=n;j++)
			{
				k++;
				if(b[k]==f)
				{
					cout<<i<<" "<<j;
					return 0;
				}
				a[j][i]=b[k];
			}
		}
	}
	return 0;
}