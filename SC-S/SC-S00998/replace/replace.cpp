#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define lc (u<<1)
#define rc (u<<1|1)
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fst first
#define Min(a,b) ((a)>(b)?(a)=(b);1)
#define Max(a,b) ((a)<(b)?(a)=(b);1)
using namespace std;
const int N=2e5+10,M=5e6+10;
bool MS;int used,id;
int n,q;
namespace ACAM
{
	int tr[M][26];
	int fail[M];
	int sz[M],res;
	void Insert(string s)
	{
		int u=0;
		for(int c:s)
		{
			c-='a';
			if(!tr[u][c])tr[u][c]=++res;
			u=tr[u][c];
		}
		sz[u]++;
	}
	void build()
	{
		queue<int>q;
		rep(c,0,25)
		if(tr[0][c])
		q.push(tr[0][c]);
//		rep(i,0,res)cout<<sz[i]<<" ";cout<<'\n';
		while(q.size())
		{
			int u=q.front();
			q.pop();
//			cout<<u<<" "<<fail[u]<<'\n';
			sz[u]+=sz[fail[u]];//不用建树了！ 
			rep(c,0,25)
			if(tr[u][c])
			{
				fail[tr[u][c]]=tr[fail[u]][c];
				q.push(tr[u][c]);
			}
			else
			{
				tr[u][c]=tr[fail[u]][c];
			}
		}
//		rep(i,0,res)cout<<sz[i]<<" ";cout<<'\n';
	}
}
int getans(string s)
{
	int u=0;
	int ans=0,tag=0;
	for(int c:s)
	{
		c-='a';
		u=ACAM::tr[u][c];
		if(tag&1)
		ans+=ACAM::sz[u];
		tag^=1;
//		cout<<ans<<" ";
	}
//	cout<<'\n';
	return ans;
}
bool MT;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	rep(i,1,n)
	{
		string s,t;
		cin>>s>>t;
		string g;
		int len=s.size();
		rep(j,0,len-1)g+=s[j],g+=t[j];
		ACAM::Insert(g);
	}
	ACAM::build();
	while(q--)
	{
//		cout<<"____________\n";
		string s,t;
		cin>>s>>t;
		if(s.size()!=t.size())
		{
			cout<<"0\n";
			continue;
		}
		string g;
		int len=s.size();
		rep(i,0,len-1)g+=s[i],g+=t[i];
		len*=2;
		int cnt=0;
		rep(i,0,len-1)
		if(i%2==0)
		{
			cnt+=(g[i]==g[i+1]);
		}
		int ans=getans(g);
		if(cnt!=len)
		{
			int l=0,r=0;
			int pos=0;
			while(g[pos]==g[pos+1])
			pos+=2;
			l=pos;
			
			pos=len-1;
			while(g[pos]==g[pos-1])
			pos-=2;
			r=pos;
			string ls;
			rep(i,l,r)ls+=g[i];
//			cout<<ans<<" "<<l<<" "<<r<<'\n';
//			cout<<g<<'\n';
//			cout<<g.substr(0,r-1)<<'\n';
//			cout<<g.substr(l+2,len-l-2)<<'\n';
//			if(r-l+1>=4)cout<<"|"<<g.substr(l+2,r-l-3)<<'\n';
//			if(r-l+1>=2)
			{
				ans-=getans(g.substr(0,r-1));//cout<<ans<<'\n';
				ans-=getans(g.substr(l+2,len-l-2));//cout<<ans<<'\n';
				if(r-l+1>=4)ans+=getans(g.substr(l+2,r-l-3));
			}
		}
		cout<<ans<<'\n';
//		used++;
//		if(used==558)exit(0);
	}
	cerr<<"Memory:"<<(&MS-&MT)/1048576.0<<"MB Time"<<clock()<<"ms\n";
}
/*
人家的都csp了，你得让让人家 

计数的内容是，对于任意一个询问串的字串，满足经过一次某个trans得到目标串的方案数。

显然可以转化为对于所有字串的权值和计数。一个子串的权值指的是其在其存在于trans集合的前者，且目标串的这部分是后者的trans的个数。

可以通过一些编码形式转化为求所有一个字符串集合在这里的出现次数之和！

不过有一点问题，如果两个端点都落在了一个不能匹配的范围 [l,r] 内，则匹配不了。

并且只能从奇数位置开始匹配。

真的不是唐吗？直接建ACAM就做完了。

空间是为了开得下ACAM 

3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/