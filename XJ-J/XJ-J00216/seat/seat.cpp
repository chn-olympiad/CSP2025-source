#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct sss
{
	int x,id;
}a[1001];
bool cmp(sss a,sss b)
{
	return a.x>b.x;
}
int n,m,t=1;
sss b[205][205];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].x;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	/*for(int i=1;i<=n*m;i++)
	{
		cout<<a[i].x<<" "<<a[i].id<<endl;
	}*/
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=m;j++)
			{
				b[i][j]=a[t];
				t++;
			}
		}
		else
		{
			for(int j=m;j>=1;j--)
			{
				b[i][j]=a[t];
				t++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(b[i][j].id==1)
			{
				cout<<i<<" "<<j;
				return 0;
			}
			//cout<<b[i][j].id<<" ";
		}
		//cout<<endl;
	}
	return 0;
}
