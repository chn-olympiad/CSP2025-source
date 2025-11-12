#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],nx,ny;
bool flag=0;
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[(i-1)*n+j];
		}
	}
	int xiaoa=a[1],tot=n*m;
	sort(a+1,a+n*m+1);
	nx=1; ny=1;
	for(int i=n*m;i>=1;i--)
	{
		if(flag==0)
		{			
			if(a[i]==xiaoa)
			{
				cout<<ny<<" "<<nx;
				return 0;
			}			
			if(nx==n)
			{
				ny++;
				flag=1;
			}
			else nx++;
		}
		else
		{
			if(a[i]==xiaoa)
			{
				cout<<ny<<" "<<nx;
				return 0;
			}			
			if(nx==1)
			{
				ny++;
				flag=0;
			}
			else nx--;			
		}
	}
return 0;
}
