#include<bits/stdc++.h>
using namespace std;
int a[10001][8];
int b[10001];
int c[10001];
int d[4];
int e[10001];
long long n,m,sum;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m;
		sum=0;
		for(int j=1;j<=m;j++)
		{
			for(int h=1;h<=3;h++)
			{
				cin>>a[j][h];
				a[j][h+3]=a[j][h];
			}
			if(a[j][2]<a[j][3])
			{
				swap(a[j][2],a[j][3]);
			}
			if(a[j][1]<a[j][2])
			{
				swap(a[j][1],a[j][2]);
			}
			if(a[j][2]<a[j][3])
			{
				swap(a[j][1],a[j][2]);
			}
			sum+=a[j][1];
		}
		b[i]=sum;
	}
		
	
	for(int i=1;i<=n;i++)
	{
		cout<<b[i]<<endl;
	}
	return 0;
}
