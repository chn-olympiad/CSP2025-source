#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int p;
int x,y;
int d=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	p=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	x=1,y=1;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==p)
		{
			cout<<x<<' '<<y;
			return 0;
		}
		if(d==1&&y==n) x++,d=-1;
		else if(d==-1&&y==1) x++,d=1;
		else y+=d;
	}
	return 0;
}
