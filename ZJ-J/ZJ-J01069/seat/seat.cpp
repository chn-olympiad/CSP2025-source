#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k1;
	cin>>n>>m;
	int s=m*n;
	for(int i=1;i<=s;i++)
	{
		int k;
		cin>>k;
		a[i]=k;
		if(i==1)
			k1=k;
	}
	sort(a+1,a+s+1);
	int aa=1;
	for(int i=1;i<=s;i++)
	{
		if(a[s+1-i]==k1)
		{
			break;
		}
		else
		{
			aa++;
		}
	}
	int x=1,y=1;
	if(aa%n==0)
	{
		x=aa/n;
		aa=aa-x*n;
	}
	else
	{
		x=aa/n+1;
		aa=aa-n*(x-1);
	}
	if(x%2==1)
	{
		if(aa==0)
			y=n;
		else
			y=aa;
	}
	else
	{
		if(aa==0)
			y=1;
		else
			y=n-aa+1;
	}
	cout<<x<<" "<<y;
	return 0;
}
