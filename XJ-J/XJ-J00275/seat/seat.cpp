#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[105],t,x,i;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	cin>>a[i];
	t=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	for(i=1;i<=n*m;i++)
	{
		if(a[i]==t)
		x=i;
	}
	cout<<(x-1)/n+1<<' ';
	if(((x-1)/n+1)%2==1)
	cout<<x-(x-1)/n*m;
	else
	cout<<n-(x-(x-1)/n*m);
	return 0;
}
