#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;

ll T,n,m,a[N][10],ta[N],sumb,tb[N];
bool A=1,B=1;

ll mmax(ll x,ll y,ll z) { return max(max(x,y),z); }
bool cmp(ll x,ll y) { return x>y; }

ll dfs(ll id,ll x,ll y,ll z)
{
	if(id>n)
	{
		return (ll)0;
	}
	ll a1=-1,a2=-1,a3=-1;
	if(x!=m) a1=a[id][1]+dfs(id+1,x+1,y,z);
	if(y!=m) a2=a[id][2]+dfs(id+1,x,y+1,z);
	if(z!=m) a3=a[id][3]+dfs(id+1,x,y,z+1);
	return mmax(a1,a2,a3);
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--)
	{
		A=1;
		B=1;
		sumb=0;
		cin >> n;
		m=n/2;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin >> a[i][j];
				if(j==1)
				{
					ta[i]=a[i][j];
					sumb+=a[i][j];
				}
				if(a[i][j]!=0 && j!=1)
				{
					A=0;
				}
				if(a[i][j]!=0 && j==3)
				{
					B=0;
				}
			}
			tb[i]=a[i][2]-a[i][1];
//			cout << tb[i] << " ";
		}
		if(A)
		{
			sort(ta+1,ta+n+1,cmp);
			ll ans=0;
			for(int i=1;i<=m;i++)
			{
				ans+=ta[i];
			}
			cout << ans << endl;
		}
		else if(B)
		{
			sort(tb+1,tb+n+1,cmp);
			ll ans=sumb;
			for(int i=1;i<=m;i++)
			{
				ans+=tb[i];
//				cout << tb[i] << " ";
			}
			cout << ans << endl;
		}
		else cout << dfs(1,0,0,0) << "\n";
	}
	return 0;
}