#include<bits/stdc++.h>
using namespace std;
struct cj{
	int bh,cj;
};
cj a[1000];
bool cmp(cj x,cj y)
{
	return x.cj>y.cj;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		a[i].bh=i;
		cin>>a[i].cj;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].bh==1)
		{
			if(i%n!=0)
			cout<<i/n+1<<" ";
			else
			cout<<i/n<<" ";
			if(i%n!=0)
			if(i/n%2==0)
			{
				if(i%n==0)
				cout<<n;
				else
				cout<<i%n;
			}
			else
			{
				if(i%n==0)
				cout<<1;
				else
				cout<<n-i%n+1;
			}
			else
			if(i/n%2!=0)
			{
				if(i%n==0)
				cout<<n;
				else
				cout<<i%n;
			}
			else
			{
				if(i%n==0)
				cout<<1;
				else
				cout<<n-i%n+1;
			}
			break;
		}
	}
	return 0;
}
