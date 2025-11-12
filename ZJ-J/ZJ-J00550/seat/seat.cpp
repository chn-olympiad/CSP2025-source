#include<bits/stdc++.h>
using namespace std;
const int N=150;
int a[N];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s=n*m;
	for(int i=1;i<=s;++i)
	{
		cin>>a[i];
	}
	int rmark=a[1];
	sort(a+1,a+1+s,cmp);
	int l=1,r=s,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(a[mid]>rmark)l=mid+1;
		else r=mid-1;
	}
	int lie,hang=l%n;
	if(hang)
	{
		lie=l/n+1;
	}
	else
	{
		lie=l/n;
	}
	if(lie%2)
	{
		if(!hang)
		{
			cout<<lie<<" "<<n;
		}
		else
		{
			cout<<lie<<" "<<hang;
		}
	}
	else
	{
		if(!hang)
		{
			cout<<lie<<" "<<1;
		}
		else
		{
			cout<<lie<<" "<<n-hang+1;
		}
	}
	return 0;
}
