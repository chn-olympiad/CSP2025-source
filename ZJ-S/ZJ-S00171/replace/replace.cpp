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
constexpr int N=200200,M=5500550;
int n,m,pcnt,tr[M],q[M],f[M],son[M][27],cnt[M]; string s1,s2; vi v[M];
il void Add(int &now,int c)
{
	if(!son[now][c]) son[now][c]=++pcnt;
	now=son[now][c];
}
il int Upd(int &now,int c)
{
	now=son[now][c];
	return tr[now];
}
il void Solve()
{
	cin>>n>>m;
	rep(i,1,n)
	{
		cin>>s1>>s2; int len=(int)s1.length();
		int l=0,r=len-1;
		while(l<=r&&s1[l]==s2[l]) ++l;
		while(l<=r&&s1[r]==s2[r]) --r;
		if(l>r) continue;
		int now=0;
		rep(j,0,len-1)
		{
			if(j==l) Add(now,0);
			Add(now,(int)s1[j]^96),Add(now,(int)s2[j]^96);
			if(j==r) Add(now,0);
		}
		++tr[now];
	}
	int hd=1,tl=0;
	rep(i,0,26)
		if(son[0][i])
			f[son[0][i]]=0,q[++tl]=son[0][i];
	while(hd<=tl)
	{
		int now=q[hd++];
		rep(i,0,26)
			if(son[now][i])
				f[son[now][i]]=son[f[now]][i],q[++tl]=son[now][i];
			else
				son[now][i]=son[f[now]][i];
	}
	rep(i,1,tl)
		tr[q[i]]+=tr[f[q[i]]];
	while(m--)
	{
		cin>>s1>>s2; int len=(int)s1.length(),len0=(int)s2.length();
		if(len!=len0) { cout<<0<<'\n'; continue; }
		int l=0,r=len-1;
		while(l<=r&&s1[l]==s2[l]) ++l;
		while(l<=r&&s1[r]==s2[r]) --r;
		int now=0,ans=0;
		rep(i,0,len-1)
		{
			if(i==l) ans+=Upd(now,0);
			ans+=Upd(now,(int)s1[i]^96),ans+=Upd(now,(int)s2[i]^96);
			if(i==r) ans+=Upd(now,0);
		}
		cout<<ans<<'\n';
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T=1;
	while(T--)
		Solve();
	return 0;
}