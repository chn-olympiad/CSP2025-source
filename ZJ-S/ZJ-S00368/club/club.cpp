#include<bits/stdc++.h>
using namespace std;
long long n;
int l[10001][4][4] = {0},al[10001][4] = {0};
void f()
{
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=3;j++)
		{
			int biggest = -1;
			for(int o = 1;o<=j;o++)
			{
				if((al[i][o] >= al[i][biggest] || biggest == -1) && l[i-1][j][o] < n/2)
				{
					biggest = o;
				}
			}
			if(l[i-1][j][0] + al[i][biggest]>=l[i][j-1][0] && biggest != -1)
			{
				l[i][j][0] = l[i-1][j][0] + al[i][biggest];
				for(int k  = 1;k<=3;k++)
				{
					l[i][j][k] = l[i-1][j][k];
				} 
				l[i][j][biggest]++;
			}
			else if(l[i][j-1][0] == 0)
			{
				l[i][j][0] = l[i][j-1][0] + al[i][biggest];
				for(int k  = 1;k<=3;k++)
				{
					l[i][j][k] = l[i][j-1][k];
				} 
				l[i][j][biggest]++;
			}
			else
			{
				for(int k  = 1;k<=3;k++)
				{
					l[i][j][k] = l[i][j-1][k];
				} 
				l[i][j][0] = l[i][j-1][0];
			}
		}
	}
//	for(int i = 1;i<=n;i++)
//	{
//		for(int j = 1;j<=3;j++)
//		{
//			cout<<l[i][j][0]<<" ";
//			for(int k = 1;k<=3;k++)
//			{
//				cout<<l[i][j][k];
//			}
//			cout<<"   ";
//		}
//		cout<<endl;
//	}
	
	cout<<l[n][3][0];
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int m;	
	cin>>m;
	for(int i = 0;i<m;i++)
	{
		cin>>n;
		for(int i = 1;i<=n;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			al[i][1] = a,al[i][2] = b,al[i][3] = c;
		}
		f();
	}

 	return 0;
}
