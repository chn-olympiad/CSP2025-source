#include<bits/stdc++.h>
using namespace std;
long long x=0;
struct kaoshi{
	long long sum,num;
}a[1010];
int n,m;
bool cmp(kaoshi x,kaoshi y)
{
	return x.sum>y.sum;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int y=n*m;
	for(int i=1;i<=y;i++) 
	{
		cin>>a[i].sum;
		a[i].num=i;	
	}
	sort(a+1,a+y+1,cmp);
	for(int j=1;j<=m;j++)
	{
		if(j%2==1)
		{
			for(int i=1;i<=n;i++)
			{
				x++;
				if(a[x].num==1)
				{
					cout<<j<<' '<<i;
					return 0;
				}
			}
		}
		else 
		{
			for(int i=n;i>=1;i--)
			{
				x++;
				if(a[x].num==1)
				{
					cout<<j<<' '<<i;
					return 0;
				}
			}
		}
	}
	return 0;
}
