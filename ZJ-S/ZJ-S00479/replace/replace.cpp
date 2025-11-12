#include<bits/stdc++.h>
#define F(i,l,r) for(int i=(l),i##end=(r);i<=i##end;++i)
#define G(i,l,r) for(int i=(l),i##end=(r);i>=i##end;--i)
#define ep emplace_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
using namespace std;
string cons(string a,string b)
{
	string c;
	int n=a.size();
	F(i,0,n-1)c+=a[i],c+=b[i];
	return c;
}
constexpr int N=2e5+9,M=5e6+9;
string a[N];int out[N];
int n,m,v;
namespace sgt
{
	int tr[M];
	void modify(int a,int b)
	{
		while(a)tr[a]+=b,a-=a&-a;
	}
	void add(int x,int op)
	{
		if(x>v)return ;
		modify(x,op);
	}
	int ask(int x)
	{
		int ans=0;
		while(x<=v)ans+=tr[x],x+=x&-x;
		return ans;
	}
}
namespace ac
{
	int fail[M],tr[M][26];
	int id;
	int root[M];
	vector<int> C[M];
	vector<pii> Q[M];
	vector<int> E[M];
	int node(int &A)
	{
		if(A==0)A=++id;
		return A;
	}
	void insert(string s)
	{
		int o=0;
		for(auto u:s)o=node(tr[o][u-'a']);
		C[o].ep(s.size());
	}
	void build()
	{
		queue<int> q;
		F(i,0,25)if(tr[0][i])q.push(tr[0][i]);
		while(q.size())
		{
			int o=q.front();q.pop();
			F(i,0,25)
			{
				if(tr[o][i])
				{
					fail[tr[o][i]]=tr[fail[o]][i];
					q.push(tr[o][i]);
				}
				else tr[o][i]=tr[fail[o]][i];
			}
		}
		F(i,1,id)E[fail[i]].ep(i);
	}
	void solve(int x)
	{
		for(auto u:C[x])sgt::add(u,1);
		for(auto u:Q[x])
		{
			out[u.x]+=sgt::ask(u.y);
		}
		for(auto u:E[x])solve(u);
		for(auto u:C[x])sgt::add(u,-1);
	}
}
int main()
{
	assert(freopen("replace.in","r",stdin));
	assert(freopen("replace.out","w",stdout));
	cin.tie(0)->sync_with_stdio(false);
	cin>>n>>m;
	F(i,1,n)
	{
		string s,t;
		cin>>s>>t;
		a[i]=cons(s,t);
		ac::insert(a[i]);
	}
	ac::build();
	F(id,1,m)
	{
		string s,t;
		cin>>s>>t;
		int n=s.size(),l=1e9,r=0;
		v=max(v,n*2);
		F(i,0,n-1)if(s[i]!=t[i])
		{
			l=min(l,i);
			r=max(r,i);
		}
		int o=0;
		F(i,0,n-1)
		{
			o=ac::tr[o][s[i]-'a'];
			o=ac::tr[o][t[i]-'a'];
			if(i>=r)
			{
				ac::Q[o].ep(id,(i-l+1)*2);
			}
		}
	}
	ac::solve(0);
	F(i,1,m)cout<<out[i]<<"\n";
	return 0;
}
