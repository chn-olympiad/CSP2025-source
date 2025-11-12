#include<bits/stdc++.h>
#define i128 __int128
#define ll long long
#define db long double
#define Pii pair<int,int>
#define fi first
#define se second

using namespace std;
const int N=1e5+10;

int n,m,p[N][5],b[5][N],l[N]; ll ans;

inline bool cmp(ll q,ll w) {return q>w;}

void solve()
{
	cin>>n; int h;
	for(int i=1;i<=n;++i)
	{
		int v=-1,fl=0;
		for(int j=1;j<=3;++j)
		{
			cin>>p[i][j];
			if(v<p[i][j]) v=p[i][j],fl=j;
		}
		b[fl][++b[fl][0]]=i; ans+=v;
	}
	for(int i=1;i<=3;++i) if(b[i][0]>n/2) h=i; m=b[h][0];
	for(int i=1;i<=m;++i)
		for(int j=1;j<=3;++j)
			if(h!=j) l[i]=max(l[i],p[b[h][i]][j]-p[b[h][i]][h]);
	sort(l+1,l+m+1,cmp);
	for(int i=1;b[h][0]>n/2;++i,--b[h][0]) ans+=l[i];
	cout<<ans<<"\n";
}

inline void clean()
{
	for(int i=1;i<=3;++i) b[i][0]=0; ans=0;
	memset(l,~0x3f,sizeof l);
}

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int t; cin>>t;
	while(t--) clean(),solve();
	return 0;
}