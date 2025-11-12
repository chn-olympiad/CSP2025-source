#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int T,n,a[N][5],f[N],kid[N];
void solve()
{
	cin>>n;
	int x=0,y=0,z=0;
	for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		f[i]=kid[i]=0;
		if(a[i][1]>a[i][2] && a[i][1]>a[i][3])	
		{
			x++;
			kid[i]=1;
			f[i]=max(a[i][2],a[i][3])-a[i][1];
		}
		if(a[i][2]>a[i][1] && a[i][2]>a[i][3])
		{
			y++;
			kid[i]=2;
			f[i]=max(a[i][1],a[i][3])-a[i][2];
		}
		if(a[i][3]>a[i][1] && a[i][3]>a[i][2])
		{
			z++;
			kid[i]=3;
			f[i]=max(a[i][1],a[i][2])-a[i][3];
		}
		ans+=max({a[i][1],a[i][2],a[i][3]});
	}
	
	if(max({x,y,z})*2<=n)
	{
		cout<<ans<<"\n";
		return ;
	}
	int k=max({x,y,z})-(n/2);
	vector<int>g;
	int op;
	if(max({x,y,z})==x)op=1;
	else if(max({x,y,z})==y)op=2;
	else op=3;
	for(int i=1;i<=n;i++)
	{
		if(kid[i]==op)
		{
			g.push_back(abs(f[i]));
		}
	}
	sort(g.begin(),g.end());
	
	for(auto v:g)
	{
		k--,ans-=v;
		if(k==0)break;
	}
	cout<<ans<<"\n";
	return ;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}
