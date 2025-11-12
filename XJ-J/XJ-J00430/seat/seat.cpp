#include<bits/stdc++.h>
using namespace std;
int sum;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,i,j,a,t;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cin>>a;
			if(i==1&&j==1) t=a;
			else
			{
				if(a>t) sum++;
			}
		}
	}
	sum++;
	int num=sum/n,nm=sum-num*n;
	if(nm==0)
	{
		if(num%2==0)
		{
			cout<<num<<' '<<1;
		}
		else
		{
			cout<<num<<' '<<n;
		}
		return 0;
	}
	if(num%2==1)
	{
		num++;
		nm=n-nm+1;
	}
	else
	{
		num++;
	}
	cout<<num<<' '<<nm;
	return 0;
}
