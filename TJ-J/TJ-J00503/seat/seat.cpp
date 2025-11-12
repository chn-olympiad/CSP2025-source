#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int n,m,maxn=-999,r,v;
int x[1005];
int sum=1;
bool f=0;
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>x[i];
	}
	v=x[1];
	sort(x+1,x+n*m+1,cmp);
	for(int i=1;i<=n;i++)
	{	
		if(i%2==1)
		{
			for(int j=1;j<=m;j++)
			{
				a[i][j]=x[sum];
				if(x[sum]==v)
				{
					cout<<i<<' '<<j;
					f=1;
					break;
				}
				sum++;
			}
		}
		if(i%2==0)
		{
			for(int j=m;j>=1;j--)
			{
				a[i][j]=x[sum];
				if(x[sum]==v)
				{
					cout<<i<<' '<<j;
					f=1;
					break;
				}
				sum++;
			}
		}
		if(f) break;
 	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
