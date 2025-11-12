#include <bits/stdc++.h>
using namespace std;
int a[11][11];
int b[121]; 
int main()
{
    freopen("seat.in","r",stdin);	
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{

	    cin>>b[i];
    }
	int d=b[1];
	for(int i=1;i<=n*m-1;i++)
	{
		for(int j=1;j<=n*m;j++)
		{
		    if(b[j]>b[i])
			{
			    int c=b[j];
				b[j]=b[i];
				b[i]=c;	
			}	
		}
	}
	int e=1;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>b[e];
			e+=1;
		}
	}
	return 0;	
} 
