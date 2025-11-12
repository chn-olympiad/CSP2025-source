#include <bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int cmp=a[1],p;
	sort(a+1,a+1+n*m,greater<int>());
	for(int i=1;i<=n*m;i++)
	{
		if(cmp==a[i])
		{
			p=i;
			break;
		}
	}
	int lie=p/n,hang=p%n;
	if(hang==0)
	{
		if(lie%2==1)
		{
			cout<<lie<<" "<<n;
		}
		else
		{
			cout<<lie<<" "<<1;
		}
	}
	else
	{
		if(lie%2==1)
		{
			cout<<lie+1<<
			" "<<n-hang+1;
		}
		else 
		{
			cout<<lie+1<<" "<<hang;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
