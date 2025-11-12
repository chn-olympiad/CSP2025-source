#include<bits/stdc++.h>
using namespace std;
int a[105];
int b[15][15];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,flag=0,i,j,sum=0;
	cin>>n>>m;
	int f=n*m;
	for(i=1;i<=f;i++)
	{
		cin>>a[i];
	}
	flag=a[1];
	sort(a+1,a+f+1,cmp);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			sum++;
			if(i%2==1)
			{
				b[j][i]=a[sum];
			}
			else if(i%2==0) 
			{
				b[m-j+1][i]=a[sum];
			}
		}
	}
	for(i=1;i<=15;i++)
	{
		for(j=1;j<=15;j++)
		{
			if(b[j][i]==flag)
			{
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
 } 
