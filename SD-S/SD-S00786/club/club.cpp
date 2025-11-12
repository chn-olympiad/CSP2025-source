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

#include<bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
int T;
int n;
int a[100005][5];
struct node1
{
	int x;
	int a[5];
}f[100005][5];
int ans;
int main()
{
//	freopen("club4.in","r",stdin);
	srand(time(0));
	cin>>T;
	while(T--)
	{
		memset(f,0,sizeof f);
		cin>>n;
		int i,j;
		for(i=1;i<=n;i++)
			for(j=1;j<=3;j++)
				cin>>a[i][j];
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=3;j++)
			{
				f[i][j] = f[i-1][j];
				if(f[i][j].a[j]>n/2)
					continue;
				if(f[i][j].a[j]+1<=n/2)
				{
					f[i][j].x = max({f[i-1][1].x,f[i-1][2].x,f[i-1][3].x})+a[i][j];
					f[i][j].a[j]++;
					cout<<f[i][j].a[j]<<endl;
				}
			}
		}
		int s = 0;
		for(i=1;i<=n;i++)
		{
			printf("i:%d\n",i);
			for(j=1;j<=3;j++)
				cout<<f[i][j].x<<' ';
			cout<<endl;
			for(j=1;j<=3;j++)
				cout<<f[i][j].a[j]<<' ';
			cout<<endl;
		}
	}
	return 0;
}
