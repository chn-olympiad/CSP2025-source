#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c=1,rn=1,rm=1;
	bool r=true;
	cin>>n>>m;
	int a[n*m+5];
	for (int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if (i>1 && a[i]>a[1])
		{
			c++;
		}
	}
	if (c%n==0)
	{
		cout<<c/n<<" "<<(c/n)*n;
	}
	else if (c%n!=0 && (c/n)%2==0)
	{
		cout<<c/n+1<<" "<<c%n;
	}
	else
	{
		cout<<c/n+1<<" "<<c%n+1;
	}
	return 0;
}
