#include<bits/stdc++.h>
using namespace std;
int b[1145],m,n,p,q,k,l;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=m*n;i++)
	{
		cin >> b[i];
	}
	p=b[1];
	sort(b+1,b+m*n+1);
	for(int i=1;i<=n*m/2;i++)
	{
		int t=b[i];
		b[i]=b[n*m-i+1];
		b[n*m-i+1]=t;
	}
	for(int i=1;i<=m*n;i++)
	{
		if(b[i]==p)
		{
			q=i;
			break;
		}
	}
	if(q%n==0)
	{
		k = q/n;
	}
	else if(q>n)
	{
		k=q/n+1;
	}
	else
	{
		k = q/n+1;
	}
	if(q%n==0)
	{
		l=n;
	}
	else if(k%2==0)
	{
		l=n-(q%n)+1;
	}
	else
	{
		l=q%n;
	}
	cout << k << " " << l;
	return 0;
}
