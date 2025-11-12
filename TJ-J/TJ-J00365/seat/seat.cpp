#include <iostream>
using namespace std;
int n,m,x[105],cj,bi[11][11],po;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	
	for (int i=1;i<=n*m;i++)
	{
		cin>>x[i];
	}
	cj=x[1];
	for (int i=1;i<=n*m;i++)
	{
		for (int j=1;j<=i;j++)
		{
			if (x[i]>x[j])
			{
				swap(x[i],x[j]);
			}
		}
	}
	for (int i=1;i<=n*m;i++)
	{
		if (x[i]==cj)
		{
			po=i;
			break;
		}
	}
	int soo=1,noww=1;
	for (int i=1;i<=m;i++)
	{
	    if (soo==1)
	    {
	    	for (int j=1;j<=n;j++)
	    	{
	    		bi[i][j]==noww;
	    		if (noww==po)
	    		{
	    			cout<<i<<" "<<j;
	    			return 0;
				}
	    		noww++;
			}
			soo=0;
		}
		else
		{
			for (int j=n;j>=1;j--)
	    	{
	    		bi[i][j]==noww;
	    		if (noww==po)
	    		{
	    			cout<<i<<" "<<j;
	    			return 0;
				}
	    		noww++;
			}
			soo=1;
		}
	}
	return 0;
}
