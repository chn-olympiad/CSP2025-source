#include <bits/stdc++.h>
#define endl '\n'
//#define int ll
#define inline
#define sh short
#define fi first
#define se second
#define db double
#define ldb long db
#define ll long long
#define ull unsigned ll
#define PII pair<int,int>
#define fopen(x) frein(x),freout(x)
#define fix(x) fixed<<setprecision(x)
#define frein(x) freopen(#x".in","r",stdin)
#define daout(x) freopen(#x".in","w",stdout)
#define freout(x) freopen(#x".out","w",stdout)
#define freans(x) freopen(#x".ans","w",stdout)
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,fread_cnt,stdin),p1==p2)?EOF:*p1++)

using namespace std;

mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
const int fread_cnt=1<<20;
const int mod=1e9+7;
const int MN=1e5+10;
//const ll inf=1e18;
const int inf=1e9;

char buf[fread_cnt],*p1=buf,*p2=buf;

template<typename T=int>
inline T read()
{
	T x=0;bool f=0;char ch=gc();
	while(ch<'0'||ch>'9')f^=ch=='-',ch=gc();
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=gc();
	return f?-x:x;
}

priority_queue<int>q;
priority_queue<PII>qq;
int n,ans,ma,nct,cnt[10],no[MN],maw[MN],mav[MN],a[MN][10];bitset<MN>vis;
//struct node{int w,peo,ide;friend bool operator<(node n1,node n2){return n1.w<n2.w;}};

inline bool solve()
{
	cin>>n,ans=0,vis.reset(),cnt[1]=cnt[2]=cnt[3]=nct=0;while(!q.empty())q.pop();
	for(int i=1;i<=n;++i)for(int j=1;j<=3;++j)cin>>a[i][j];
	for(int i=1,x=0,y=0;i<=n;mav[i]=x,maw[i]=y,++cnt[y],++i,x=y=0)for(int j=1;j<=3;++j)if(x<a[i][j])x=a[i][j],y=j;
	n>>=1;for(int i=1;i<=3;++i)if(cnt[i]>n)ma=i;
	if(!ma)
	{
		for(int i=1;i<=n*2;++i)ans+=mav[i];
		return cout<<ans<<endl,0;
	}
	for(int i=1;i<=n*2;++i)if(maw[i]==ma)qq.push({mav[i],i});
	for(int i=1;i<=n;++i)ans+=qq.top().fi,vis[qq.top().se]=1,qq.pop();
	while(!qq.empty())qq.pop();
	for(int i=1,x=0;i<=n*2;ans+=x,mav[i]=x,++i,x=0)if(!vis[i])for(int j=1;j<=3;++j)if(j!=ma)x=max(x,a[i][j]);
	for(int i=1;i<=n*2;++i)if(!vis[i])no[++nct]=i;
	for(int i=1,x=0;i<=n*2;++i,x=0)if(vis[i])
	{
		for(int j=1;j<=3;++j)if(j!=ma)x=max(x,a[i][j]);
		q.push(x-a[i][ma]);
	}
	for(int i=1,x,y;i<=nct;++i)
	{
		x=q.top(),y=a[no[i]][ma]-mav[no[i]]+x;
		if(y>0)ans+=y,q.pop(),q.push(x-y);
	}
	cout<<ans<<endl;
	
//	cin>>n;for(int i=1;i<=n*3;++i)cin>>p[i],c[i]=i;
//	sort(c+1,c+n*3+1,[&](int &w1,int &w2){return p[w1]<p[w2];});
//	for(int i=1;i<=n*3;++i)p[c[i]]=i;
//	for(int i=1;i<=n;cout<<endl,++i)for(int j=1;j<=3;++j)cout<<p[(i-1)*3+j]<<' ';
	
//	cin>>n,ans=0,vis.reset(),cnt[1]=cnt[2]=cnt[3]=0;while(!q.empty())q.pop();
//	for(int i=1;i<=n;++i)for(int j=1;j<=3;++j)cin>>a[i][j];
//	for(int i=1,x;i<=n;++i)for(int j=1;j<=3;++j)
//	{
//		x=a[i][j];for(int k=1;k<=3;++k)if(j!=k)x-=a[i][k];
//		q.push({x,i,j});
//	}
//	n>>=1;
//	while(!q.empty())
//	{
//		node now=q.top();q.pop();if(vis[now.peo]||cnt[now.ide]>=n)continue;
//		ans+=a[now.peo][now.ide],vis[now.peo]=true,++cnt[now.ide];
//	}
//	cout<<ans<<endl;
	return 0;
}

signed main()
{
	frein(club);freout(club);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	system("fc club.out club5.ans");
	int t=1;cin>>t;while(t--)solve();
//	while(!solve());
//	solve();
	return 0;
}
/*
#include <bits/stdc++.h>
#define endl '\n'
//#define int ll
#define inline
#define sh short
#define fi first
#define se second
#define db double
#define ldb long db
#define ll long long
#define ull unsigned ll
#define PII pair<int,int>
#define fopen(x) frein(x),freout(x)
#define fix(x) fixed<<setprecision(x)
#define frein(x) freopen(#x".in","r",stdin)
#define daout(x) freopen(#x".in","w",stdout)
#define freout(x) freopen(#x".out","w",stdout)
#define freans(x) freopen(#x".ans","w",stdout)
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,fread_cnt,stdin),p1==p2)?EOF:*p1++)

using namespace std;

mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
const int fread_cnt=1<<20;
const int mod=1e9+7;
const int MN=1e6+10;
//const ll inf=1e18;
const int inf=1e9;

char buf[fread_cnt],*p1=buf,*p2=buf;

template<typename T=int>
inline T read()
{
	T x=0;bool f=0;char ch=gc();
	while(ch<'0'||ch>'9')f^=ch=='-',ch=gc();
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=gc();
	return f?-x:x;
}

int n,ans,a[MN][3],b[MN],cnt[10];

inline void dfs(int k)
{
	if(k==n+1)
	{
		int res=0;
		for(int i=1;i<=3;++i)if(cnt[i]>n/2)return ;
		for(int i=1;i<=n;++i)res+=a[i][b[i]];
		ans=max(ans,res);
		return ;
	}
	for(int i=1;i<=3;++i)
	{
		b[k]=i,++cnt[i],dfs(k+1),--cnt[i];
	}
}

inline bool solve()
{
	cin>>n;
	for(int i=1;i<=n;++i)for(int j=1;j<=3;++j)cin>>a[i][j];
	dfs(1),cout<<ans<<endl;
	return 0;
}

signed main()
{
	frein(club);freans(club);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	system("fc .out .ans");
//	int t=1;cin>>t;while(t--)solve();
//	while(!solve());
	solve();
	return 0;
}
*/