#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int n,m,a[N],now,l,r,mid,ns,x,y;
bool cmp(int as,int bs)
{
	return as>bs;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	now=a[1];
	sort(a+1,a+n*m+1,cmp);
	l=1;r=n*m;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(a[mid]>now) l=mid+1;
		else r=mid-1;
	}
	ns=l;
	x=(ns-1)/n+1;
	if(x%2==0)
	{
		y=n-(ns-1)%n;
	}
	else
	{
		y=(ns-1)%n+1;
	}
	cout<<x<<" "<<y;
	return 0;
}
