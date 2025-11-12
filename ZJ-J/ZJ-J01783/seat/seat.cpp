#include<bits/stdc++.h>
using namespace std;
struct data
{
	int k,s;
}a[501];
int n,m;
bool cmp(data x,data y)
{
	return x.s>y.s;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].s;
		a[i].k=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].k==1)
		{
			int h,l;
			if(i%n==0)l=i/n;
			else l=i/n+1;
			if(l%2==1)
			{
				h=i%n;
				if(h==0)h=n;
			}
			else
			{
				h=n-(i%n)+1;
				if(h==n+1)h=1;
			}
			cout<<l<<" "<<h;
			break;
		}
	}
	return 0;
}