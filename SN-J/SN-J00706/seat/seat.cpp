#include<bits/stdc++.h>
using namespace std;
int a[105],n,m,s;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	int l=a[0];
	sort(a,a+n*m);
	reverse(a,a+n*m);
	for(int i=1;i<=m;i++)
	{
		if(i%2==0)
		{
			for(int j=n;j>=1;j--)
			{
				if(a[s]==l)
				{
					cout<<i<<" "<<j;
					return 0;
				}
				s++;
			}
		}
		else
		{
			for(int j=1;j<=n;j++)
			{
				if(a[s]==l)
				{
					cout<<i<<" "<<j;
					return 0;
				}
				s++;
			}
		}
	}
	return 0;
}
