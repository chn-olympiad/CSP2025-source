#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair <int,int> 
const ll base1 = 233,mod1 = 1e9 + 7;
const ll base2 = 331,mod2 = 1e9 + 9;
const int N = 2e5,M = 5e6;
int n,q,k,ans[N + 5];
string s1,s2,sl[N + 5],sr[N + 5];
string t1,t2,tl[N + 5],tr[N + 5];
map <pair <pii,pii> ,int> ID;
vector <int> vs[N + 5],vt[N + 5];
struct Trie_L
{
	struct node
	{
		int nxt[26],cnt;
	}a[M / 2 + 5];
	int rt,cntnode;
	int gnode()
	{
		int id = ++cntnode;
		for(int i = 0;i < 26;i++)a[id].nxt[i] = 0;
		a[id].cnt = 0;
		return id;
	}
	void init()
	{
		cntnode = 0;
		rt = gnode();
	}
	void add(int x,int v)
	{
		int id = rt;
		for(int i = 0;i < sl[x].size();i++)
		{
			int c = sl[x][i] - 'a';
			if(!a[id].nxt[c])a[id].nxt[c] = gnode();
			id = a[id].nxt[c];
		}
		a[id].cnt += v;
	}
	int query(int x)
	{
		int id = rt,res = 0;
		for(int i = 0;i < tl[x].size();i++)
		{
			int c = tl[x][i] - 'a';
			if(!a[id].nxt[c])break;
			res += a[id].cnt;
			id = a[id].nxt[c];
		}
		res += a[id].cnt;
		return res;
	}
}trie_l;
struct Trie_R
{
	struct node
	{
		int nxt[26];
	}a[M + 5];
	vector <int> s[M + 4],t[M + 4];
	int rt,cntnode;
	int gnode()
	{
		int id = ++cntnode;
		for(int i = 0;i < 26;i++)a[id].nxt[i] = 0;
		s[id].clear();t[id].clear();
		return id;
	}
	void init()
	{
		trie_l.init();
		cntnode = 0;
		rt = gnode();
	}
	void add_s(int x)
	{
		int id = rt;
		for(int i = 0;i < sr[x].size();i++)
		{
			int c = sr[x][i] - 'a';
			if(!a[id].nxt[c])a[id].nxt[c] = gnode();
			id = a[id].nxt[c];
		}
		s[id].push_back(x);
	}
	void add_t(int x)
	{
		int id = rt;
		for(int i = 0;i < tr[x].size();i++)
		{
			int c = tr[x][i] - 'a';
			if(!a[id].nxt[c])a[id].nxt[c] = gnode();
			id = a[id].nxt[c];
		}
		t[id].push_back(x);
	}
	void solve(int id)
	{
		for(auto now : s[id])trie_l.add(now,1);
		for(auto now : t[id])
			ans[now] = trie_l.query(now);
		for(int i = 0;i < 26;i++)
			if(a[id].nxt[i])solve(a[id].nxt[i]);
		for(auto now : s[id])trie_l.add(now,-1);
	}
}trie_r;
void solve(int x)
{
	trie_r.init();
	for(auto now : vs[x])trie_r.add_s(now);
	for(auto now : vt[x])trie_r.add_t(now);
	trie_r.solve(1);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i = 1;i <= n;i++)
	{
		cin>>s1>>s2;
		int l = 0,r = s1.size() - 1;
		while(l <= r&&s1[l] == s2[l])l++;
		while(l <= r&&s1[r] == s2[r])r--;
		if(l <= r)
		{
			ll h11 = 0,h12 = 0,h21 = 0,h22 = 0;
			for(int j = l;j <= r;j++)
				h11 = h11 * base1 + s1[j] % mod1,
				h12 = h12 * base2 + s1[j] % mod2,
				h21 = h21 * base1 + s2[j] % mod1,
				h22 = h22 * base2 + s2[j] % mod2;
			pair <pii,pii> now = {{h11,h12},{h21,h22}};
			if(ID.find(now) == ID.end())ID[now] = ++k;
			vs[ID[now]].push_back(i);
		}
		l--;while(l >= 0)sl[i].push_back(s1[l]),l--;
		r++;while(r < s1.size())sr[i].push_back(s1[r]),r++;
	}
	for(int i = 1;i <= q;i++)
	{
		cin>>t1>>t2;
		if(t1.size() != t2.size())continue;
		int l = 0,r = t1.size() - 1;
		while(l <= r&&t1[l] == t2[l])l++;
		while(l <= r&&t1[r] == t2[r])r--;
		if(l <= r)
		{
			ll h11 = 0,h12 = 0,h21 = 0,h22 = 0;
			for(int j = l;j <= r;j++)
				h11 = h11 * base1 + t1[j] % mod1,
				h12 = h12 * base2 + t1[j] % mod2,
				h21 = h21 * base1 + t2[j] % mod1,
				h22 = h22 * base2 + t2[j] % mod2;
			pair <pii,pii> now = {{h11,h12},{h21,h22}};
			if(ID.find(now) != ID.end())
				vt[ID[now]].push_back(i);
		}
		l--;while(l >= 0)tl[i].push_back(t1[l]),l--;
		r++;while(r < t1.size())tr[i].push_back(t1[r]),r++;
	}
	for(int i = 1;i <= k;i++)
		if(!vt[i].empty())solve(i);
	for(int i = 1;i <= q;i++)
		cout<<ans[i]<<"\n";
}