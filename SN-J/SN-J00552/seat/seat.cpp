#include<bits/stdc++.h>
using namespace std;
int n,m,a1,a[110],ai;
inline bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a1;
	a[1]=a1;
	for(int i=2;i<=n*m;i++) cin>>a[i];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a1==a[i])
		{
			ai=i;
			break;
		}
	}
	if(!(ai%n))
	{
		cout<<ai/n<<' ';
		if((ai/n)%2) cout<<n;
		else cout<<1;
	}
	else
	{
		cout<<ai/n+1<<' ';
		if((ai/n+1)%2) cout<<ai%n;
		else cout<<n+1-(ai%n);
	}
	cout<<'\n';
	return 0;
}
