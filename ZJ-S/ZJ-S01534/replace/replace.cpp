#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int n,q;
struct node
{
	ull hasha,hashb;
	int id;
	bool operator < (const node a) const
	{
		if(hasha!=a.hasha)
			return hasha<a.hasha;
		return hashb<a.hashb;
	}
	bool operator <= (const node a) const
	{
		if(hasha!=a.hasha)
			return hasha<a.hasha;
		return hashb<=a.hashb;
	}
	bool operator != (const node a) const
	{
		return hasha!=a.hasha||hashb!=a.hashb;
	}
}a[200005],b[200005];
ull base=1145141;
string s1[200005],s2[200005],t1[200005],t2[200005];
int son1[5000005][26],son2[5000005][26],c1=1,c2=1,m1[5000005],m2[5000005],lg[1<<26],id[200005],ans[200005],dfn[5000005],sz[5000005],tot;
vector<int> v1[5000005],v2[5000005];
struct BIT
{
	int tr[5000005];
	void add(int x,int y){for(;x<=c2;x+=(x&-x))tr[x]+=y;}
	int query(int x){int s=0;for(;x;x-=(x&-x))s+=tr[x];return s;}
}tr;
void dfsinit(int pos)
{
	sz[pos]=1;
	dfn[pos]=++tot;
	int cur=m2[pos];
	for(;cur;cur&=(cur-1))
		dfsinit(son2[pos][lg[cur&-cur]]),sz[pos]+=sz[son2[pos][lg[cur&-cur]]];
}
void dfs(int pos)
{
	for(int x:v1[pos])
		tr.add(dfn[x],1),tr.add(dfn[x]+sz[x],-1);
	for(int x:v2[pos])
		ans[x]=tr.query(dfn[id[x]]);
	int cur=m1[pos];
	for(;cur;cur&=(cur-1))
		dfs(son1[pos][lg[cur&-cur]]);
	for(int x:v1[pos])
		tr.add(dfn[x],-1),tr.add(dfn[x]+sz[x],1);
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=0;i<26;i++)
		lg[1<<i]=i;
	for(int i=1;i<=n;i++)
	{
		string cs1,cs2;
		cin>>cs1>>cs2;
		int p=0,q=cs1.size()-1;
		while(p<cs1.size()&&cs1[p]==cs2[p])
			p++;
		while(q&&cs1[q]==cs2[q])
			q--;
		if(p==cs1.size())
			continue;
		ull val1=0,val2=0;
		for(int j=p;j<=q;j++)
		{
			val1=val1*base+(ull)(cs1[j]-'a'+1);
			val2=val2*base+(ull)(cs2[j]-'a'+1);
		}
		a[i]={val1,val2,i};
		for(int j=0;j<p;j++)
			s1[i]+=cs1[j];
		reverse(s1[i].begin(),s1[i].end());
		for(int j=q;j<cs1.size();j++)
			s2[i]+=cs1[j];
	}
	for(int i=1;i<=q;i++)
	{
		string ct1,ct2;
		cin>>ct1>>ct2;
		int p=0,q=ct1.size()-1;
		while(p<ct1.size()&&ct1[p]==ct2[p])
			p++;
		while(q&&ct1[q]==ct2[q])
			q--;
		ull val1=0,val2=0;
		for(int j=p;j<=q;j++)
		{
			val1=val1*base+(ull)(ct1[j]-'a'+1);
			val2=val2*base+(ull)(ct2[j]-'a'+1);
		}
		b[i]={val1,val2,i};
		for(int j=0;j<p;j++)
			t1[i]+=ct1[j];
		reverse(t1[i].begin(),t1[i].end());
		for(int j=q;j<ct1.size();j++)
			t2[i]+=ct1[j];
	}
	sort(a+1,a+n+1),sort(b+1,b+q+1);
	int p=1,lst=1;
	for(int i=1;i<=n;i++)
		if(a[i]!=a[i+1]||i==n)
		{
			while(p<=q&&b[p]<a[i])
				p++;
			int t=p;
			while(t<=q&&b[t]<=a[i])
				t++;
			if(p<t)
			{
				for(int j=1;j<=c1;j++)
				{
					while(m1[j])
					{
						son1[j][lg[m1[j]&-m1[j]]]=0;
						m1[j]&=(m1[j]-1);
					}
					v1[j].clear(),v2[j].clear();
				}
				for(int j=1;j<=c2;j++)
				{
					int t=m2[j];
					while(m2[j])
					{
						son2[j][lg[m2[j]&-m2[j]]]=0;
						m2[j]&=(m2[j]-1);
					}
					dfn[j]=0;
				}
				c1=c2=1;
				for(int j=lst;j<=i;j++)
				{
					int pos1=1,pos2=1;
					int x=a[j].id;
					for(int k=0;k<s1[x].size();k++)
					{
						if(!son1[pos1][s1[x][k]-'a'])
							m1[pos1]|=(1<<s1[x][k]-'a'),son1[pos1][s1[x][k]-'a']=++c1;
						pos1=son1[pos1][s1[x][k]-'a'];
					}
					for(int k=0;k<s2[x].size();k++)
					{
						if(!son2[pos2][s2[x][k]-'a'])
							m2[pos2]|=(1<<s2[x][k]-'a'),son2[pos2][s2[x][k]-'a']=++c2;
						pos2=son2[pos2][s2[x][k]-'a'];
					}
					v1[pos1].push_back(pos2);
				}
				for(int j=p;j<t;j++)
				{
					int pos1=1,pos2=1;
					int x=b[j].id;
					for(int k=0;k<t1[x].size();k++)
					{
						if(!son1[pos1][t1[x][k]-'a'])
							break;
						pos1=son1[pos1][t1[x][k]-'a'];
					}
					for(int k=0;k<t2[x].size();k++)
					{
						if(!son2[pos2][t2[x][k]-'a'])
							break;
						pos2=son2[pos2][t2[x][k]-'a'];
					}
					v2[pos1].push_back(x);
					id[x]=pos2;
				}
				tot=0;
				dfsinit(1);
				dfs(1);
			}
			t=p;
			lst=i+1;
		}
	for(int i=1;i<=q;i++)
		cout<<ans[i]<<"\n";
}
//end at 16:39