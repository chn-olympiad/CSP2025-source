#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define pb push_back
const int N=1e5+10;
const int P=1e9+7;

int ma[4],n,m,ans,t;
int a[N][4];
struct Node
{
	int d,id;
}d[N];

bool cmp(Node x,Node y)
{
	return x.d>y.d;
}

void solve()
{
	ans=ma[0]=ma[1]=ma[2]=0;
	cin>>n;
	for(int i=1;i<=n;i++)for(int j=0;j<3;j++)cin>>a[i][j];
	for(int i=1;i<=n;i++)
	{
		if(a[i][0]>max(a[i][1],a[i][2]))ma[0]++;
		if(a[i][1]>max(a[i][2],a[i][0]))ma[1]++;
		if(a[i][2]>max(a[i][1],a[i][0]))ma[2]++;
//		cout<<ma[0]<<" "<<ma[1]<<" "<<ma[2]<<'\n';
	}
	int x=max({ma[0],ma[1],ma[2]});
	if(x>n/2)
	{
		if(ma[0]==x)m=0;
		else if(ma[1]==x)m=1;
		else m=2;
		for(int i=1;i<=n;i++)
		{
			d[i].id=i;
			d[i].d=a[i][m]-max(a[i][(m+2)%3],a[i][(m+1)%3]);
		}
		sort(d+1,d+n+1,cmp);
		for(int i=1;i<=n/2;i++)ans+=a[d[i].id][m];
		for(int i=n/2+1;i<=n;i++)ans+=max(a[d[i].id][(m+2)%3],a[d[i].id][(m+1)%3]);
	}
	else
	{
		for(int i=1;i<=n;i++)ans+=max({a[i][1],a[i][2],a[i][0]}); 
	}
	cout<<ans<<'\n';
}

signed main()
{
 	freopen("club.in","r",stdin);
 	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--)solve();
	return 0;
}

