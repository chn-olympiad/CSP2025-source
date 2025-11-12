#include<bits/stdc++.h>
using namespace std;
int n,q;
int cnt[5400005];
const int M=5000000;
struct segtree{
	struct node{
		int lc,rc,val;
	}tree[7000005];
	int cnt;
	#define M(l,r) ((l+r)>>1)
	#define lc(x) (tree[x].lc)
	#define rc(x) (tree[x].rc)
	void insert(int &p,int l,int r,int x,int k)
	{
		if(!p) p=++cnt;
		tree[p].val+=k;
		if(l==r) return ;
		int mid=M(l,r);
		if(x<=mid) insert(lc(p),l,mid,x,k);
		else insert(rc(p),mid+1,r,x,k);
	}
	int query(int p,int l,int r,int x)
	{
		if(!p) return 0;
		if(l==r) return tree[p].val;
		int mid=M(l,r);
		if(x<=mid) return query(lc(p),l,mid,x);
		else return query(rc(p),mid+1,r,x)+tree[lc(p)].val;
	}
}T;
struct trie{
	int tree[5000005][26];
	vector<int> G[5000005];
	int cnt;
	int insert(int &rt,string s,int id,int tid)
	{
		//cerr<<"INS:"<<id<<" "<<tid<<" "<<s<<"\n";
		if(!rt) rt=++cnt;
		int p=rt;
		for(auto c:s)
		{
			c-='a';
			if(!tree[p][c])
			{
				tree[p][c]=++cnt;
				if(tid==2) G[p].emplace_back(cnt);
			}
			p=tree[p][c];
		}
		if(tid==1) G[p].emplace_back(id);
		return p;
	}
}T1,T2;
int rt[5000005],rt1[200005],rt2[200005];
string s1[200005],s2[200005],t1[200005],t2[200005];
int p1[200005],p2[200005];
int val[5000005];
const int mod=1e9+7,mod1=998244353;
int base,rd[127],base1,rd1[127];
int l[5000005],r[5000005],dc;
mt19937 rnd(114514);
map<pair<int,int>,int> mp;
int idx;
void dfs(int x)
{
	l[x]=++dc;
	for(auto g:T2.G[x]) dfs(g);
	r[x]=dc;
	//cerr<<x<<" "<<l[x]<<" "<<r[x]<<"\n";
}
int search(int x,string s)
{
	for(auto c:s)
	{
		c-='a';
		if(!T2.tree[x][c]) return x;
		x=T2.tree[x][c];
	}
	return x;
}
int dfs1(int x,string s,int p)
{
	//cerr<<"HAHAHA:"<<s<<"\n";
	//cerr<<"???QU:"<<x<<" "<<p<<"\n";
	int ans=T.query(rt[x],1,M,p);
	for(auto c:s)
	{
		c-='a';
		//cerr<<"GO:"<<x<<" "<<(int)c<<" "<<T1.tree[x][c]<<"\n";
		if(!T1.tree[x][c]) return ans;		
		//cerr<<"???QU:"<<x<<" "<<p<<"\n";
		x=T1.tree[x][c];
		ans+=T.query(rt[x],1,M,p);
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	base=rnd()%(mod-1)+1;
	base1=rnd()%(mod1-1)+1;
	for(int i='a';i<='z';i++) rd[i]=rnd()%(mod-1)+1;
	for(int i='a';i<='z';i++) rd1[i]=rnd()%(mod1-1)+1;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		if(s1[i]==s2[i]) continue ;
		int j1=0,j2=(int)s1[i].length()-1;
		string ss,tt;
		while(s1[i][j1]==s2[i][j1]) ss+=s1[i][j1],j1++;
		while(s1[i][j2]==s2[i][j2]) tt+=s2[i][j2],j2--;
		reverse(ss.begin(),ss.end());
		reverse(tt.begin(),tt.end());
		int hsh=0,hsh1=0;
		for(int j=j1;j<=j2;j++)
		{
			//cerr<<s1[i][j];
			hsh=1ll*hsh*base%mod+rd[s1[i][j]];
			hsh1=1ll*hsh1*base1%mod1+rd1[s1[i][j]];
			if(hsh>=mod) hsh-=mod;
			if(hsh>=mod1) hsh-=mod1;
		}
		for(int j=j1;j<=j2;j++)
		{
			//cerr<<s2[i][j];
			hsh=1ll*hsh*base%mod+rd[s2[i][j]];
			hsh1=1ll*hsh1*base1%mod1+rd1[s2[i][j]];
			if(hsh>=mod) hsh-=mod;
			if(hsh>=mod1) hsh-=mod1;
		}
		//cerr<<"\n";
		if(!mp[{hsh,hsh1}]) mp[{hsh,hsh1}]=++idx;
		//cerr<<i<<" "<<hsh<<"\n";
		p1[i]=T1.insert(rt1[mp[{hsh,hsh1}]],ss,i,1);
		p2[i]=T2.insert(rt2[mp[{hsh,hsh1}]],tt,i,2);
	}
	for(int i=1;i<=idx;i++)
	{
		dfs(rt2[i]);
	}
	for(int i=1;i<=T1.cnt;i++)
	{
		for(auto j:T1.G[i])
		{
			int pl=l[p2[j]],pr=r[p2[j]]+1;
			//cerr<<i<<" "<<j<<" "<<pl<<" "<<pr<<"\n";
			T.insert(rt[i],1,M,pl,1);
			if(pr<M) T.insert(rt[i],1,M,pr,-1);
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t1[i]>>t2[i];
		int j1=0,j2=(int)t1[i].length()-1;
		string ss,tt;
		while(t1[i][j1]==t2[i][j1]) ss+=t1[i][j1],j1++;
		while(t1[i][j2]==t2[i][j2]) tt+=t1[i][j2],j2--;
		reverse(ss.begin(),ss.end());
		reverse(tt.begin(),tt.end());
		int hsh=0,hsh1=0;
		for(int j=j1;j<=j2;j++)
		{
			//cerr<<t1[i][j];
			hsh=1ll*hsh*base%mod+rd[t1[i][j]];
			hsh1=1ll*hsh1*base1%mod1+rd1[t1[i][j]];
			if(hsh>=mod) hsh-=mod;
			if(hsh>=mod1) hsh-=mod1;
		}
		for(int j=j1;j<=j2;j++)
		{
			//cerr<<t2[i][j];
			hsh=1ll*hsh*base%mod+rd[t2[i][j]];
			hsh1=1ll*hsh1*base1%mod1+rd1[t2[i][j]];
			if(hsh>=mod) hsh-=mod;
			if(hsh>=mod1) hsh-=mod1;
		}
		//cerr<<"\n";
		//cerr<<i<<" "<<hsh<<" "<<"\n";
		if(!mp[{hsh,hsh1}])
		{
			cout<<"0\n";
			continue ;
		}
		int id=mp[{hsh,hsh1}];
		int p=search(rt2[id],tt);
		cout<<dfs1(rt1[id],ss,l[p])<<"\n";
	}
}