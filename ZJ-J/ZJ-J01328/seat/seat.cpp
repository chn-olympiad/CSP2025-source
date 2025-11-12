#include<bits/stdc++.h>
using namespace std;
string x;
long long n,i,l,h,k,m;
struct XX
{
	long long id,cj;
}a[5050];
bool cmp(XX x,XX y)
{
	return x.cj>y.cj;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	{
		cin>>a[i].cj;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(i=1;i<=n*m;i++)
	{
		if(a[i].id==1)
		{
			k=i;
			break;
		}
	}
	h=1;
	l=1;
	i=1;
	while(i<=n*m)
	{
		if(i==k)
		{
			cout<<l<<" "<<h;
			return 0;
		}
		while(h<n)
		{
			h++;
			i++;
			if(i==k)
			{
				cout<<l<<" "<<h;
				return 0;
			}
		}
		l++;
		i++;
		if(i==k)
		{
			cout<<l<<" "<<h;
			return 0;
		}
		while(h>1)
		{
			h--;
			i++;
			if(i==k)
			{
				cout<<l<<" "<<h;
				return 0;
			}
		}
		i++;
		l++;
		if(i==k)
		{
			cout<<l<<" "<<h;
			return 0;
		}
	}
	return 0;
}