#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int maxn=1e7+10,inf=2e9,mod=1e9+7;
int n,q,base1=131,mod1=1e9+7,base2=271,mod2=998244853,idx,trie[maxn][27],num,fail[maxn],cnt[maxn];
map<pair<pii,pii >,int> mp;
pii chash(string s,int l,int r)
{
	int x1=0,x2=0;
	for(int i=l;i<=r;i++)
	{
		x1=(x1*base1+s[i]-'a')%mod1;
		x2=(x2*base2+s[i]-'a')%mod2;
	}
	return {x1,x2};
}
struct ACAM{
	int root;
	void init()
	{
		root=++num;
		for(int i=0;i<=26;i++) trie[root][i]=++num; 
	}
	void insert(string s)
	{
		int rt=root;
		for(int i=0;i<s.length();i++)
		{
			int f;
			if(s[i]=='#') f=26;
			else f=s[i]-'a';
			if(!trie[rt][f]) trie[rt][f]=++num;
			rt=trie[rt][f];
		}
		cnt[rt]++;
	}
	void build()
	{
		queue<int> q;
		for(int i=0;i<=26;i++)
		{
			fail[trie[root][i]]=root,q.push(trie[root][i]);
		}
		while(!q.empty())
		{
			int u=q.front();q.pop();
			cnt[u]+=cnt[fail[u]];
			for(int i=0;i<=26;i++)
			{
				if(trie[u][i])
				{
					fail[trie[u][i]]=trie[fail[u]][i];
					q.push(trie[u][i]);
				}
				else trie[u][i]=trie[fail[u]][i];
			}
		}
	}
	int calc(string s)
	{
		int rt=root,ret=0;
		for(int i=0;i<s.length();i++)
		{
			int f;
			if(s[i]=='#') f=26;
			else f=s[i]-'a';
			rt=trie[rt][f];
			ret+=cnt[rt];
		}
		return ret;
	}
} tr[maxn];
void write(int x)
{
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string s1,s2,t1,t2,t;
		cin>>s1>>s2,t1=t2=t="";
		int l=-1,r=-1,id;
		pii hsh1,hsh2;
		for(int i=0;i<s1.length();i++)
		{
			if(s1[i]!=s2[i]) r=i;
		}
		for(int i=s1.length()-1;i>=0;i--)
		{
			if(s1[i]!=s2[i]) l=i;
		}
		if(l==-1 and r==-1) continue;
		hsh1=chash(s1,l,r),hsh2=chash(s2,l,r);
		if(!mp[{hsh1,hsh2}]) mp[{hsh1,hsh2}]=++idx,tr[idx].init();
		id=mp[{hsh1,hsh2}];
		for(int i=0;i<l;i++) t=t+s1[i];
		t=t+'#';
		for(int i=r+1;i<s1.length();i++) t=t+s1[i];
		tr[id].insert(t);
	}
	for(int i=1;i<=idx;i++) tr[i].build();
	for(int _=1;_<=q;_++)
	{
		string s1,s2,t="";
		cin>>s1>>s2;
		if(s1.length()!=s2.length())
		{
			write(0),putchar('\n');
			continue;
		}
		int l=-1,r=-1,id;
		pii hsh1,hsh2;
		for(int i=0;i<s1.length();i++)
		{
			if(s1[i]!=s2[i]) r=i;
		}
		for(int i=s1.length()-1;i>=0;i--)
		{
			if(s1[i]!=s2[i]) l=i;
		}
		hsh1=chash(s1,l,r),hsh2=chash(s2,l,r);
		if(!mp[{hsh1,hsh2}]) 
		{
			write(0),putchar('\n');
			continue;
		}
		id=mp[{hsh1,hsh2}];
		for(int i=0;i<l;i++) t=t+s1[i];
		t=t+'#';
		for(int i=r+1;i<s1.length();i++) t=t+s1[i];
		write(tr[id].calc(t)),putchar('\n');
	}
	return 0;
}
