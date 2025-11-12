#include<iostream>
using namespace std;
int a[100];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,t,l,c,sum=0;
	cin>>m>>n;
	for(int i=1;i<=m*n;i++)
	{
		cin>>a[i];
	}
	l=a[1];
	int s=m*n;
	for(int i=1;i<=m*n;i++)
	{
		for(int j=1;j<=s;j++)
		{
			if(a[j]<a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
		s--;
	}

	for(int i=1;i<=m*n;i++)
	{
		if(a[i]==l)
		{
			c=i;
		}
	}
	int q=1;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			sum++;
			if(sum==c)
			{
				if(i%2==0)
				{
					cout<<i<<" "<<(n+1)-j;
				}
				else{
					cout<<i<<" "<<j;
				}
			}
		} 
	}
	return 0;
}
//行数n与列数 m
