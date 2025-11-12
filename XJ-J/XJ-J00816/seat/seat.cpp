#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Node
{
	int sc;
	bool r;
}a[11451];

bool cmp(Node x,Node y)
{
	return x.sc>y.sc;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].sc;
		a[i].r=0;
	}a[1].r=1;
	int xb;
	sort(a+1,a+1+(n*m),cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].r==1)xb=i;
	}
	int ans1,ans2;
	ans1=ans2=0;
	if(xb%n==0&&xb>n)
	{
		ans2=xb/n;
	}
	else if(xb<=n)ans2=1;
	else ans2=xb/n+1;
	
	if(ans2%2==0)
	{
		ans1=n-(xb%n)+1;
	}
	else if(xb<=n) ans1=xb;
	else ans1=xb%n;
	
	
	cout<<ans2<<' '<<ans1;
	return 0;
	
 } 

