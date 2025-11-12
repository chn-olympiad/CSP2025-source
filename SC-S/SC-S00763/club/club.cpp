#include<bits/stdc++.h>
using namespace std;
int m[1000][1000];
int s[1000];
int y[1000];
int a,b,c,v;
int n;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		for(int k=1;k<=n;k++)
		{
			for(int f=1;f<=3;f++)
			{
				cin>>m[k][f];
			}	
			for(int j=1;j<=3;j++)
			{
				if(y[k]<m[k][j])
				{
					y[k]=m[k][j];
				}
			}
			
		}
		for(int j=1;j<=n;j++)
		{
			s[i]=s[i]+y[j];
		}
	}
	for(int i=1;i<=t;i++)
	{
		cout<<s[i]<<endl;
	}
	return 0;
}