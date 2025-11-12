#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],mx=0;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<=n*m;i++)
	{
		if(a[1]<=a[i])
		{
			mx++;
		}
	}
	cout<<mx/n+1<<" "<<mx%n+1;
	return 0;
}