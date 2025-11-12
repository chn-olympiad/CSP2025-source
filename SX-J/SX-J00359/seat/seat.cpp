#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,a[N],t,nm,x,y;
bool cmp(int q,int w)
{
	return q>w;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	nm=n*m;
	for(int i=1;i<=nm;i++)
	{
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+nm+1,cmp);
	for(int i=1,q=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++,q++)
			{
				if(a[q]==t)
				{
					x=j;
					y=i;
				}
			}
		}
		else
		{
			for(int j=n;j>=1;j--,q++)
			{
				if(a[q]==t)
				{
					x=j;
					y=i;
				}
			}
		}
	}
	cout<<y<<' '<<x;
	return 0;
}
