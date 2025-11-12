#include<bits/stdc++.h>
using namespace std;
long long n,m,t,f;
long long a[200];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1) t=a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(t==a[i]) 
		{
			f=i;
			break;
		}
	}
	if((f-1)/n%2==0)
	{
		cout<<(f-1)/n+1<<" ";
		if(f%n==0) cout<<n;
		else cout<<f%n;
	}
	else
	{
		if(f%n==0) cout<<f/n<<" "<<1;
		else cout<<f/n+1<<" "<<n-(f%n)+1;
	}
	return 0;
}
