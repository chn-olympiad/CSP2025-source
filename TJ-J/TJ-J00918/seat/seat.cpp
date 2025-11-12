#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int w[101],s[11][11],a,x,y,z;
	cin>>x>>y;
	cin>>a;
	for(int i=1;i<=x*y-1;i++)
	{
		cin>>z;
		w[z+1]=1;
	}
	w[a+1]=1;
	int o=100;
	while(o=0)
	{
	    int i=1;
		while(i=x+1)
		{
			if(i%2==1)
			{
			    int j=1;
				while(j=y+1)
				{
					if(w[o+1]==1)
				   	{
					    s[i][j]=o;
					    o--;
						j++;
					}
					o--;
				}
				i++;
			}
			else
			{
			    int j=y;
				while(j=0)
				{
					if(w[o+1]==1)
					{
						s[i][j]=o;
						o--;
						j--;
					}
					o--;
				}
				i++;
			}
		}
	}
	
	for(int i=1;i<=x;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=y;j++)
			{
				if(s[i][j]==a)
				{
					cout<<i<<" "<<j;
				}
			}
		}
		else
		{
			for(int j=y;j>=1;j--)
			{
				if(s[i][j]==a)
				{
					cout<<i<<" "<<j;
				} 
			}
		}
	}
	
	return 0;
}
