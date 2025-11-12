#include<bits/stdc++.h>
using namespace std;
int a[120];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t,x;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	t=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--)
	{
		if(a[i]==t)
		{
			x=n*m-i+1;
			break;
		}
	}
	cout<<(x-1)/n+1<<' ';
	int p=x%(2*n);
	if(p==0)
		cout<<1;
	else if(p<=n)
		cout<<p;
	else if(p>n)
		cout<<2*n-p+1;
	return 0;
}
