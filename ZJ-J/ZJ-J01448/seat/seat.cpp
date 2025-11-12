#include<bits/stdc++.h>
using namespace std;
int a[1001];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int bla;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	bla=a[1];
	int op=896796;
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==bla)
		{
			op=n*m-i+1;
			break;
		}
	}
	int h,l;
	h=op/n;
	if(op%n!=0)
	{
		h++;
	}
	l=op%n;
	if(l==0)
	{
		l=n;
	}
	if(h%2==0)
	{
		l=n-l+1;
	}
	cout<<h<<' '<<l<<endl;
	return 0;
}
