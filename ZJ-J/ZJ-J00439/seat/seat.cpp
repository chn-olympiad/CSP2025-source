#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long n,m;
long long a[N];
long long t;
bool cmp(long long a,long long b)
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
	t=a[1];
	sort(a+1,a+n*m+1,cmp);
	long long l=1,r=n*m;
	while(l<r)
	{
		long long mid=(l+r)/2;
		if(a[mid]>t) l=mid+1;
		else r=mid;
	}
	long long k=l%(n*2),t=l/(n*2);
	if(k<=n&&k>0) 
	{
		cout<<t*2+1<<" "<<k;
	}
	else if(k>n&&k<=2*n)
	{
		cout<<t*2+2<<" "<<n*2-k+1;
	}
	else if(k==0)
	{
		cout<<t*2<<" "<<0;
	}
	return 0;
}
