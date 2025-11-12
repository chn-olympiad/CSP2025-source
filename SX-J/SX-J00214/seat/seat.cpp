#include<bits/stdc++.h>
using namespace std;
int n,m,a[999999];
int csp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("sest.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int b=a[1];
	sort(a+1,a+1+n*m,csp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==b)
		{
			if(i%n!=0) cout<<i/n+1<<" ";
			if(i%n==0)cout<<i/n<<" ";
			if(i%n==0) cout<<n;
			if(i%n!=0&&(i/n)%2==0) cout<<i%n;
			if(i%n!=0&&(i/n)%2!=0) cout<<n-(i%n)+1;
		}
	}
	return 0;
}