#include<bits/stdc++.h>
using namespace std;
const int N = 1e7 + 1e6 + 10, M = 2e5 + 10;
int cnt[N], tr[N][27], is1[N], rt1[N], rt2[N], idx = 1;
int he[N], ne[N], eid;
string s1, s2, e[N];
void add(int a, string &b){e[++eid]=b;ne[eid]=he[a];he[a]=eid;}

void insert()
{
	cin>>s1>>s2;
	int i, len = s1.size();
	for(i=0;i<len;i++) if(s1[i]!=s2[i]) break;
	if(i==len) return;
	int a1 = i;
	for(i=len-1;i>=0;i--) if(s1[i]!=s2[i]) break;
	int a2 = i, p = 1;
	for(i=a1;i<=a2;i++)
	{
		int &y = tr[p][s1[i]-'a'];
		if(!y) y = ++idx;
		p = y;
	}
	if(!tr[p][26]) tr[p][26] = ++idx;
	p = tr[p][26];
	for(i=a1;i<=a2;i++)
	{
		int &y = tr[p][s2[i]-'a'];
		if(!y) y = ++idx;
		p = y;
	}
	if(!rt1[p]) rt1[p] = ++idx, is1[p] = 1;
	// printf("p %dd %d %d\n", p, a1, a2);
	p = rt1[p];
	for(i=a1-1;i>=0;i--)
	{
		int &y = tr[p][s1[i]-'a'];
		if(!y) y = ++idx;
		p = y;
	}
	string ss = "";
	for(i=a2+1;i<len;i++) ss += s1[i];
	add(p,ss);
}

void clone(int x, int y)
{
	cnt[y] = cnt[x];
	int i;
	for(i=0;i<26;i++) tr[y][i] = tr[x][i];
}
int ins2(int a, string &s)
{
	clone(a,++idx);
	int p = idx;a = idx;
	// printf("nowa %d\n", a);
	for(auto c:s) clone(tr[a][c-'a'],++idx), tr[a][c-'a'] = idx, a = idx;
	// printf("yy%d\n", a);
	cnt[a]++;
	return p;
}

queue<int>q;
void build(int x)
{
	// if(x!=6) return;/////////////////////jidezhushi
	q.push(rt1[x]);
	while(!q.empty())
	{
		int d = q.front(), i;q.pop();
		for(i=he[d];i;i=ne[i]) rt2[d] = ins2(rt2[d],e[i]);
		// printf("d %dd %d %d %d\n", d, rt2[d], cnt[rt2[d]], cnt[tr[rt2[d]]['x'-'a']]);
		for(i=0;i<26;i++) if(tr[d][i]) rt2[tr[d][i]] = rt2[d], q.push(tr[d][i]);
		// printf("build%d %dd %d\n", d, rt2[d], cnt[rt2[d]]);
	}
}

void getqu()
{
	cin>>s1>>s2;
	if(s1.size()!=s2.size()) return printf("0\n"), void();
	int i, len = s1.size();
	for(i=0;i<len;i++) if(s1[i]!=s2[i]) break;
	if(i==len) return;
	int a1 = i;
	for(i=len-1;i>=0;i--) if(s1[i]!=s2[i]) break;
	int a2 = i, p = 1;
	for(i=a1;i<=a2;i++)
	{
		int &y = tr[p][s1[i]-'a'];
		if(!y) y = ++idx, is1[y] = 1;
		p = y;
	}
	p = tr[p][26];
	for(i=a1;i<=a2;i++)
	{
		int &y = tr[p][s2[i]-'a'];
		if(!y) y = ++idx, is1[y] = 1;
		p = y;
	}
	// printf("p %d %d %d %d\n", p, a1, a2, cnt[rt2[rt1[p]]]);
	p = rt1[p];
	// printf("p %dd %d %d %d\n", p, cnt[rt2[p]], cnt[tr[tr[rt1[p]]['x'-'a']]['a'-'a']], tr[tr[rt1[p]]['x'-'a']]['a'-'a']);
	if(!p) return printf("0\n"), void();
	// printf("p %ddd\n", p);
	for(i=a1-1;i>=0;i--) if(tr[p][s1[i]-'a']) p = tr[p][s1[i]-'a'];else break;
	p = rt2[p];
	if(!p) return printf("0\n"), void();
	int ans = cnt[p];
	// printf("nowans %dd %d %d\n", ans, p, a2);
	for(i=a2+1;i<len;i++) p = tr[p][s1[i]-'a'], ans += cnt[p];
	printf("%d\n", ans);
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, q, i;
	cin>>n>>q;
	for(i=1;i<=n;i++) insert();
	int nowidx = idx;
	for(i=1;i<=nowidx;i++) if(is1[i]) build(i);
	while(q--) getqu();
	return 0;
}