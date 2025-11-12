#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],cnt,q;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cnt=n*m;
	for(int i=1;i<=cnt;i++)
	{
		cin>>a[i];
	}
	q=a[1];
	sort(a+1,a+1+cnt,cmp);
	int k;
	for(int i=1;i<=cnt;i++)
	{
		if(a[i]==q)
		{
			k=i;
			break;
		}
	}
	int c,r=0;
	c=(k+n-1)/n;
	if(c%2)
	{
		r=k-(c-1)*n;
	}
	else
	{
		r=n-(k-(c-1)*n)+1;
	}
	cout<<c<<" "<<r;
	return 0;
}

