#include <bits/stdc++.h>
using namespace std;
int n,m;
struct ks
{
	int c,a;
};
ks a[101];
bool cmp(ks x,ks y)
{
	return x.c>y.c;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].c;
		a[i].a=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i*m-m+j].a==1)
			{
				if(i%2==0)
				{
					int ll;
					ll=n-j+1;
					j=ll;
				}
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
