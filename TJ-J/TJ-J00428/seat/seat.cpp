#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],p; 
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	p=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==p)
		{
			cout<<((i-1)/n)+1<<' ';
			if((((i-1)/n)+1)%2==1)
			{
				cout<<((i-1)%n)+1;
			}
			else
			{
				cout<<n-((i-1)%n);
			}
			return 0;
		}
	}
	return 0;
}
