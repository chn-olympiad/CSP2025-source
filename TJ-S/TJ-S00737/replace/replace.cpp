#include <bits/stdc++.h>
using namespace std;
int m,p;
int m2[2][1000];
int p2[2][1000]; 
int main ()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdin);
	cin>>m>>p;
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=2;j++)
		{
		cin>>m2[i][j];
		}
	}
	for(int i=0;i<=p;i++)
	{
		for(int j=0;j<=2;j++)
		{
		cout<<p2[i][j];	
		}
	}
	
	return 0;
}
