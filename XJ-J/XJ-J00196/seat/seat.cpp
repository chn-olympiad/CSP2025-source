#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,a[105],paixu[105],b[105],w[15][15],q[15][15],xiabiao,sum=0,endd=2,x=1,enda=2;
	cin>>m>>n;
	for(int i=1;i<=m*n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1;i<=m*n;i++)
	{
		sum=0;
		for(int j=1;j<=m*n;j++)
		{
			if(a[j]>sum)
			{
				sum=a[j];
				xiabiao=j;
				paixu[i]=a[j];
			}
		}
		a[xiabiao]=0;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			w[i][j]=paixu[x];
			x++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(j%2==0)
			{
				for(int x=n;x>=1;x++)
				{
					if(endd==2)
					{
						if(b[1]==w[j][x])
						{
							endd=j;
							enda=x;
						}
					}
					else
					{
						break;
					}
				}
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(endd==2)
			{
				if(b[1]==w[i][j])
				{
					endd=i;
					enda=j;
				}
			}
			else
			{
				break;
			}
		}
	}
	cout<<endd<<' '<<enda;
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
