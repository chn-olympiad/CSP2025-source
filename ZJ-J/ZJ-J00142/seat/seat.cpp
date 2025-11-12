#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[105],R;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	R=a[1];
	sort(a+1,a+n*m+1,cmp);
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
			for(int j=1;j<=n;j++)
			{
				cnt++;
				if(a[cnt]==R)
				{
					cout<<i<<' '<<j<<endl;
					return 0;
				}
			}
		else
			for(int j=n;j>=1;j--)
			{
				cnt++;
				if(a[cnt]==R)
				{
					cout<<i<<' '<<j<<endl;
					return 0;
				}
			}
	}
	return 0;
}