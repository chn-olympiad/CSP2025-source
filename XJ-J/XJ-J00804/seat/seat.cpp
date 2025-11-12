#include <bits/stdc++.h>
using namespace std;
int main()
{
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],maxa=0;
	cin>>n>>m;
	
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int xR=a[1];
	

	for(int j=1;j*j<=n*m;j++)
	{
		for(int i=1;i*i<=n*m;i++)
		{
			if(a[i]<a[i+1])
			{
				maxa=a[i];
				a[i]=a[i+1];
				a[i+1]=maxa;
			}
		}
	}
	int k=0;
	
	for(int j=1;j<=m;j++)
	{
		if(j%2!=0)
		{
			for(int i=1;i<=n;i++)
			{
				k++;
				if (a[k]==xR)
				{
				    cout<<j<<" "<<i;
					return 0;
				}
			}
		}
		else
		{
			for(int i=n;i>=1;i--)
			{
				k++;
				if (a[k]==xR) 
				{
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
