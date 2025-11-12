#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MXN = 5000100;
const int base= 97;
const int mod = 998244353;
int n;
ll hss[MXN],pw[MXN];

struct trr{
	int d,fail,hd;
	int s[26];
}a[MXN<<1];
int pcnt;

struct gg{
	ll v;
	int next;
}g[MXN<<1];
int gcnt;
void add(int p,ll v){
	g[++gcnt].v=v;
	g[gcnt].next=a[p].hd;
	a[p].hd=gcnt;
}

void insert(string s1,string s2)
{
//	cout<<"Ins:"<<s1<<" "<<s2<<endl;
	int n=s1.size(),f=0,p=0;
	for(int i=0;i<n;i++)
	{
		int c=s1[i]-'a';
		if(!a[p].s[c]) a[p].s[c]=++pcnt,a[pcnt].d=a[p].d+1;
		p=a[p].s[c];
	}
	ll hs=0;
	for(int i=0;i<n;i++) hs=(hs*base+s2[i]-'a')%mod;
	add(p,hs);
}
queue<int>q;
void ffail()
{
	q.push(0);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int i=0;i<26;i++) 
		{
			if(a[u].s[i]) 
			{
				int v=a[u].s[i];
				int f=a[u].fail;
				while(f&&!a[f].s[i]) f=a[f].fail;
				if(a[f].s[i]) f=a[f].s[i];
				a[v].fail=f;
				q.push(v);
				if(u==0) a[v].fail=0;
			}
		}
	}
}

inline ll get(int l,int r)
{
	return (hss[r]-(l>0?hss[l-1]:0)*pw[r-l]%mod+mod)%mod;
}

inline void read(string &s)
{
	char ch=getchar();s="";
	while(ch<'a'||ch>'z') ch=getchar();
	while(ch>='a'&&ch<='z') s=s+ch,ch=getchar();
}
string s1,s2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int Q; cin>>n>>Q;
	pw[0]=1; for(int i=1;i<MXN;i++) pw[i]=pw[i-1]*base%mod;
	for(int i=1;i<=n;i++)
	{
		read(s1);read(s2);
		insert(s1,s2);
	}
	ffail();
//	for(int i=0;i<=pcnt;i++)
//	{cout<<i<<" ";
//		for(int j=0;j<26;j++)
//			if(a[i].s[j]) cout<<char(j+'a')<<":"<<a[i].s[j]<<"-"<<a[a[i].s[j]].fail<<"   ";
//		cout<<endl;
//	}
	for(int i=1;i<=Q;i++)
	{
		read(s1);read(s2);
//		cout<<s1<<" "<<s2<<endl;
		int len=s1.size(),p=0;
		int ans=0,L=MXN,R=0;
		for(int j=0;j<len;j++)
		{
			if(s1[j]!=s2[j])
			{
				L=min(L,j);
				R=max(R,j);
			}
		}
//		cout<<L<< ' '<<R<<endl;
		for(int j=0;j<len;j++) 
			hss[j]=((j>0?hss[j-1]:0)*base+s2[j]-'a')%mod;
		for(int j=0;j<len;j++)
		{
			int c=s1[j]-'a';
			while(p&&!a[p].s[c]) p=a[p].fail;
			if(a[p].s[c]) p=a[p].s[c];
			int d=p;
//			cout<<j<<":"<<p<<endl;
			while(d&&j>=R&&j-a[d].d<L)
			{
				for(int k=a[d].hd;k;k=g[k].next)
				{
					if(g[k].v==get(j-a[d].d+1,j)) ans++;
//					cout<<j-a[d].d+1<<" "<<j<<" "<<ans<<" "<<g[k].v<<" "<<get(j-a[d].d+1,j)<<endl;
				}
				d=a[d].fail;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
