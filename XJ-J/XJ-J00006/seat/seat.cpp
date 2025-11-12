#include<bits/stdc++.h>
using namespace std;
long long int i,j,n,m,r,a[15][15],k,s;
int b[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	r=n*m;
	for(i=1;i<=r;i++)
	{
		cin>>b[i];
	}
	s=b[1];
    sort(b+1,b+1+r,greater<int>());
    i=1; j=1;
    for(k=1;k<=r;k++)
    {
    	a[i][j]=b[k];
    	if(j%2==0)
    	{
    		i++;
    		if(i>n)
    		{
    			i--;
    			j++;
			}
		}
		else
		{
			i--;
			if(i<1)
			{
				i++;
				j++;
			}
		}
	}
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	{
		if(a[i][j]==s)
		{
			cout<<i<<" "<<j;
			return 0;
		}
	}
	
}

	
