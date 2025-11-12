#include<bits/stdc++.h>
using namespace std;
int n,m,t,x,ans1,ans2;
int a[100001];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	t=a[1];
	int y=n*m;
	sort(a+1,a+1+y);
	for(int i=n*m;i>=1;i--)
	{
		if(a[i]==t)
		{
			x=n*m-i+1;
			break;
		}
	}
	if(x%n!=0)
	{
		ans1=x/n+1;
		if(ans1%2==0)
		{
			ans2=n-x%n+1;
		}
		else if(ans1%2==1)
		{
			ans2=x%n;	
		}
	}
	else
	{
		ans1=x/n;
		ans2=n;
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}