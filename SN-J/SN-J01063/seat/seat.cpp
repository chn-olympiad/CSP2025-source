#include<bits/stdc++.h>
using namespace std;
int a[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int x=a[1],l=n*m;
	sort(a+1,a+n*m);
	for(int j=1;j<=n;j++)
	{
		if(j%2==1)
		{
			for(int i=1;i<=m;i++)
			{
				l--;				
				if(a[l]==x)
				{
					cout<<j<<" "<<i;
					return 0; 
				}
			}		
		}
		else
		{
			for(int i=m;i>=1;i--)
			{
				l--;				
				if(a[l]==x)
				{
					cout<<j<<" "<<i;
					return 0; 
				}		
			}
		}
	}
	return 0;
} 
