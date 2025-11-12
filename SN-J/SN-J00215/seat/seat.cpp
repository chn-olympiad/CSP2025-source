#include<bits/stdc++.h>
using namespace std;
const int maxn=200;
int n, m, a[maxn], val, c, r;
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
	val=a[1];
	sort(a+1, a+n*m+1, cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==val)
		{
			if(i%n) c=i/n+1;
			else c=i/n;
			r=i%n;
			if(c%2)
			{
				if(r==0) r=n;
			}
			if(c%2==0)
			{
				if(r==0) r=1;
				else r=n-r+1;
			}
			cout<<c<<" "<<r;
			return 0; 
		}
	}
	return 0;
}
