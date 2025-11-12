#include<bits/stdc++.h>
using namespace std;
const int MAXX=10005;
int main()
{
	int z,n,i,j,t,a[MAXX][3]={0},b[5][MAXX]={0},maxx=0,maxi,s[5]={0},sum=0;
	cin>>z;
	for(int q=1;q<=z;q++)
	{
		cin>>n;
		t=n/2;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=3;j++)
			{
				cin>>a[i][j];
			}
		}
		for(i=1;i<=n;i++)
		{
			maxx=0;
			for(j=1;j<=3;j++)
			{
				if(a[i][j]>maxx)
				{
					maxx=a[i][j];
					maxi=j;
				}
			}
			b[maxi][i]=maxx;
			s[maxi]++;
		}
		for(i=1;i<=3;i++)
		{
			if(s[i]<=t)
			{
				for(j=1;j<=s[i];j++)
				{
					if(b[i][j]==0)
					{
						j--;
						continue;
					}
					sum+=b[i][j];
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
} 
