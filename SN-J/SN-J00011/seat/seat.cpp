#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[101];
	int b[10][10];
	int n,m;
	int ans=1;
	int cnt=1;
	int lie=1,hang=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];	
	}
	for(int i=2;i<=n*m;i++)
	{
		if(a[i]>a[1])
		{
			ans++;
		}
	}
	if(ans==n*m)
	{
		cout<<m<<" "<<n;
		return 0;
	}
	for(int i=1;i<=n*m;i++)
	{
		if(cnt==ans)
		{
			cout<<lie<<" "<<hang;
			return 0;
		}
		else
		{
			cnt++;
			if(lie%2==1)
			{
				if(hang==n)
				{
					lie++;
				}
				else
				{
					hang++;
				}
			}
			else
			{
				if(hang==1)
				{
					lie++;
				}
				else
				{
					hang--;
				}
			}
		}
	}
	return 0;
}
