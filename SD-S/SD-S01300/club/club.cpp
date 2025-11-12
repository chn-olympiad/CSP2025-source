#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
int a;
int minx = 10000000;
int maxx;
int maxy;
int maxz;
int z[100009][5];
int c[100009];
int sum[1000009];
int k = 0;
int k2;
int re;
void qc()
{
	for(int i = 1;i<=3;i++) z[i][4] = 1000000;
	minx = 4; 
	for(int i = 1;i<=a;i++)
		{
		for(int j = 1;j<=3;j++)
			{
			if(z[i][j] > z[i][maxx])
				{
					maxx = j;
				}
			if(z[i][j] < z[i][minx])
				{
					minx = j;
				}
			int midx =6-maxx-minx;
			
			c[i] = z[i][maxx]-z[i][midx];
			}
		}
	
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	while(n>0)
	{
	
		cin>>a;
		for(int i = 1;i<=a;i++)
		{
			for(int j = 1;j<=3;j++)
			{
				cin>>z[i][j];
			}	
		}
		qc();
		for(int j = 1;j<=a;j++)
		{
			for(int i = 1;i<=a;i++)
			{
				if(c[i]>maxy)
				{
					maxy = c[i];
					k = i;
				}
			}
			for(int i = 1;i<=3;i++)
			{
				if(z[k][i] > maxz)
				{
					k2 = i;
					maxz = z[k][k2];
				}
			}
			re+=z[k][k2];
			sum[k2]++;
			for(int i = 1;i<=3;i++)
			{
				z[k][i] = 0;
			}
			qc();
			if(sum[k2] >= a/2)
			{
				for(int i = 1;i<=a;i++)
				{
					z[i][k2] = 0;
				}
				qc();
			}
			maxx = 0;
			maxy = 0;
			maxz = 0;
			minx = 4;
		}
		cout<<re<<endl;
		re = 0;
		
		for(int i = 1;i<=a;i++)
		{
			sum[i] = 0;
			c[i] = 0;
		}
		n--;
	}
	return 0;
}

