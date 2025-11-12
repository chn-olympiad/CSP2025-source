#include<bits/stdc++.h>
using namespace std;
#define pb push_back
struct node
{
	int fail,fa,num,fl,hs;
	int son[26];
	multiset<int> s;
	vector<int> g,h,l;
}tr[1000050];
string s[200005],t[200005],a[200005],b[200005];
int st[200005],en[200005],sr[200005],ed[200005],hah[200005],hsh[200005],ans[200005],cnt,now;
void ins(int k,int dep)
{
	if(sr[now]+dep>ed[now])
	{
		tr[k].fl=1;
		tr[k].g.pb(now);
		tr[k].h.pb(hsh[now]);
		return ;
	}
	if(tr[k].son[a[now][sr[now]+dep]-'a']==0) tr[k].son[a[now][sr[now]+dep]-'a']=++cnt,tr[cnt].fa=k,tr[cnt].num=a[now][sr[now]+dep]-'a';
	ins(tr[k].son[a[now][sr[now]+dep]-'a'],dep+1);
}
void get_fail()
{
	queue<int> q;
	q.push(1);
	tr[1].fail=0;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		tr[x].fail=tr[tr[x].fa].son[tr[x].num];
		tr[tr[x].fail].l.pb(x);
	}
}
void query(int k,int dep)
{
	if(tr[k].fl==1) tr[k].s.insert(hah[now]);
	if(sr[now]+dep>ed[now]) return;
	while(tr[k].son[a[now][sr[now]+dep]-'a']==0&&k!=1) k=tr[k].fail;
	query(tr[k].son[a[now][sr[now]+dep]-'a'],dep+1);
}
void dfs(int x)
{
	if(tr[x].l.size()!=0) tr[x].hs=tr[x].l[1]; 
	for(int i=0;i<tr[x].l.size();i++)
	{
		int v=tr[x].l[i];
		if(tr[v].s.size()>tr[tr[x].hs].s.size()) tr[x].hs=v;
	}
	dfs(tr[x].hs);
	for(int i=0;i<tr[x].l.size();i++)
	{
		int v=tr[x].l[i];
		if(v==tr[x].hs) continue;
		dfs(v);
	}
	
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int i,j,n,q;
	cin>>n>>q;
	for(i=1;i<=n;i++)
	{
		cin>>s[i]>>t[i];
		if(s[i].size()==t[i].size())
		{
			st[i]=s[i].size()-1;
			en[i]=-1;
			for(j=0;j<s[i].size();j++) if(s[i][j]!=t[i][j]) st[i]=min(st[i],j),en[i]=max(en[i],j);
			for(j=st[i];j<=en[i];j++) hah[i]=hah[i]*131+(t[i][j]-'a'+1);
		}
		else st[i]=en[i]=-1;
	}
	for(i=1;i<=q;i++)
	{
		cin>>a[i]>>b[i];
		now=i;
		if(a[i].size()==b[i].size())
		{
			sr[i]=a[i].size()-1;
			ed[i]=-1;
			for(j=0;j<a[i].size();j++) if(a[i][j]!=b[i][j]) sr[i]=min(sr[i],j),ed[i]=max(ed[i],j);
			for(j=sr[i];j<=ed[i];j++) hsh[i]=hsh[i]*131+(b[i][j]-'a'+1);
			ins(1,0);
		}
		else ans[i]=0;
	}
	get_fail();
	for(i=1;i<=n;i++) now=i,query(1,0);
	dfs(1);
}
