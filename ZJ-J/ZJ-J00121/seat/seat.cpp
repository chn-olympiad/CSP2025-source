#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],sum1,sum2,c,r;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	sum1=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==sum1)
		{
			sum2=i;
			break;
		}
	c=ceil(1.0*sum2/n);
	if(c%2==0)
	{
		r=n-sum2%n+1;
		if(sum2%n==0)
			r=1;
	}
	else
	{
		r=sum2%n;
		if(sum2%n==0)
			r=n;
	}
	cout<<c<<" "<<r;
	return 0;
}
