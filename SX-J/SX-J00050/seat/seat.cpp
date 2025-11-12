#include<bits/stdc++.h>
using namespace std;
int n,m,s=0,pm=0,a[109],b[19][19];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int z=n*m;
	for(int i=1;i<=z;i++)
	{
		cin>>a[i];
	}
	pm=a[1];
	sort(a+1,a+1+z,cmp);
	for(int i=1;i<=z;i++)
	{
		if(a[i]==pm)
		{
			pm=i;
			break;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				s++;
				if(s==pm)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				s++;
				if(s==pm)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}