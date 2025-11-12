#include<bits/stdc++.h>
using namespace std;
#define il inline
#define fi first
#define se second
#define mk make_pair
#define eb emplace_back
#define rep(i,l,r) for(int i=(l); i<=(r); ++i)
#define rep_(i,l,r) for(int i=(l); i>=(r); --i)
typedef long long lr;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T>il T Max(T x,T y) { return x>y? x:y; }
template<typename T>il T Min(T x,T y) { return x<y? x:y; }
constexpr int N=100100;
int n,f[N][3],cnt[3],id[3][N],del[N];
il void Solve()
{
	cin>>n;
	rep(i,1,n)
		rep(j,0,2)
			cin>>f[i][j];
	rep(j,0,2)
		cnt[j]=0;
	int ans=0;
	rep(i,1,n)
	{
		int mx=-1,pos=0;
		rep(j,0,2)
			if(f[i][j]>mx)
				mx=f[i][j],pos=j;
		id[pos][++cnt[pos]]=i,ans+=mx;
	}
	rep(j,0,2)
		if(cnt[j]>(n>>1))
		{
			int m=cnt[j]-(n>>1),a=(j+1)%3,b=(j+2)%3;
			rep(i,1,cnt[j])
				del[i]=f[id[j][i]][j]-Max(f[id[j][i]][a],f[id[j][i]][b]);
			sort(del+1,del+1+cnt[j]);
			rep(i,1,m)
				ans-=del[i];
		}
	cout<<ans<<'\n';
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T; cin>>T;
	while(T--)
		Solve();
	return 0;
}