#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n,m,l,x,g,z;
	cin>>n>>m;
	cin>>z;
	l=n*m;
	int s[l]={};
	int c[n][m]={};
for(int i=0;i<l;i++)
{
	cin>>s[i];
}
for(int i=0;i<l;i++)
{
    for(int j=0;j<l-1;j++)
    {
		if(s[j+1]>s[j])
		{
            x=s[j+1];
            s[j+1]=s[j];
            s[j]=x;
		}
    }
}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(i==0 && j==0)
			{
				g=1;
			}
			else if(i==0)
			{
				g=1*j;
			}
			else if(j==0)
			{
				g=1*i;
			}
			else
			{
				g=i*j;
			}
			c[i][j]=s[g];
			if(g==z-1)
			{
				cout<<i<<" "<<j;
			}
		}
	}
return 0;
}

