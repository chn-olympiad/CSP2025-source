#include<bits/stdc++.h>
using namespace std;
int n,m,a[205],t,p;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	t=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--)
	{
		p++;
		if(a[i]==t)
			break;
	}
	for(int i=1;i<=m;i++)
	{
		if(p>=(i-1)*n+1 && p<=i*n)
		{
			if(i%2==1)
				cout<<i<<" "<<p-i*n+n;
			else
				cout<<i<<" "<<i*n-p+1;
			break;
		}
	}
	return 0;
}
