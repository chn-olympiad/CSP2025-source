#include<bits/stdc++.h>
#define ll long long
#define db double
const int N=1e6+10;
using namespace std;
int n,m,a[N],ans;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0),cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int t=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>a[++t];
			if(i==1&&j==1)
				ans=a[t];
		}
	sort(a+1,a+t+1,cmp);
	t=0;
	for(int i=1;i<=n;i++)
	{
		if(i%2)
			for(int j=1;j<=m;j++)
			{
				t++;
				if(a[t]==ans)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		else
			for(int j=m;j>=1;j--)
			{
				t++;
				if(a[t]==ans)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
	}
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/
