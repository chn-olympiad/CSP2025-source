#include<bits/stdc++.h>
using namespace std;
int n,m,xr,a[105],t;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	t=n*m;
	for(int i=1;i<=t;i++)
		scanf("%d",&a[i]);
	xr=a[1];
	sort(a+1,a+t+1);
	for(int i=1;i<=t;i++)
		if(a[i]==xr)
		{
			i=t-i+1;
			cout<<((i-1)/n+1)<<" ";
			cout<<((((i-1)/n+1)%2==1)?(i-1)%n+1:m-(i-1)%n);
			break;
		}
	return 0;
}
