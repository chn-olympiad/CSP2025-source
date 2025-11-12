#include<bits/stdc++.h>
using namespace std;
typedef int ll;
struct st
{
	ll num,id;
	bool operator < (const st &u)const
	{
		return num>u.num;
	}
};
const ll N=110;
ll n,m,now,ans[N][N];
st a[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].num;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1);
	for(int j=1;j<=m;j++)
	{
		if(j%2)
		{
			for(int i=1;i<=n;i++)
			{
				ans[i][j]=a[++now].id;
			}
		}
		else
		{
			for(int i=n;i>=1;i--)
			{
				ans[i][j]=a[++now].id;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(ans[i][j]==1)
			{
				cout<<j<<" "<<i<<"\n";
				return 0;
			}
		}
	}
	return 0;
}