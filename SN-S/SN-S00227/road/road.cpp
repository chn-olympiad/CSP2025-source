#include<bits/stdc++.h>
using namespace std;
int a[3003][3003];
int t,n,m;
int main()
{
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
		cin>>m;
		for(int i=1;i<=3;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>a[i][j];
			}
		}	
	

	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2 
10 9 8
4 0 0
*/
