#include <bits/stdc++.h>
using namespace std;
int n,m,t,x,a1,num=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a1;
	t=n*m;
	for (int i=1; i<t; i++)
	{
		cin>>x;
		if (x>a1) num++;
	}
	if (num%n==0)
	{
		cout<<num/n<<" ";
		if ((num/n)%2) cout<<n;
		else cout<<1;
	}
	else
	{
		cout<<num/n+1<<" ";
		if ((num/n)%2) cout<<n+1-(num%n);
		else cout<<num%n;
	}
	return 0;
}
