#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,k;
int a[1010];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(x==a[i])
		{
			k=i;
			break;
		}
	}
	x=k/n;
	if(k%n!=0)	x++;
	y=k%n;
	if(y==0)	y=m;
	if(x%2==0)
	{
		y=n+1-y;
	}
	cout<<x<<' '<<y;
	return 0;
}
