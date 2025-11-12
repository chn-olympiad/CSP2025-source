#include<bits/stdc++.h>
using namespace std;
long long a[10000000],b,n,m,c,d,e[10000000];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	b=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++) e[i]=a[m*n-i+1];
	for(int i=1;i<=n;i++)
	{
		
		if(i%2!=0)
		{
			for(int j=1;j<=m;j++)
			{
				d++;
				if(e[n*(i-1)+j]==b) 
				{
					cout<<i<<' '<<j;
					return 0; 
				}
			}
		}	
		else 
		{
			for(int j=1;j<=m;j++)
			{
				
				if(e[n*(i-1)+m-j+1]==b) 
				{
					cout<<i<<' '<<j;
					return 0; 
				}
			}	
		}
	}	
	return 0;
}	
