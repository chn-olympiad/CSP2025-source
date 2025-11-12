#include<bits/stdc++.h>
#define M 5000010
#define N 200005
using namespace std;
int n,q,cnt=4,tot,m,c[M],dfn[M],oud[M],ans[N];
string s1,s2;
map<pair<int,int>,int> mp;
vector<array<int,26> > ch;
vector<array<int,3> > tx[N];
vector<array<int,5> > t[N];
void dfs(int u){
	dfn[u]=++m;
	for(int i=0;i<26;i++){
		if(!ch[u][i])	continue;
		dfs(ch[u][i]);
	}
	oud[u]=m;
}
void add(int i,int x){
	for(;i<=m;i+=i&-i)	c[i]+=x;
}
int query(int i){
	int res=0;
	for(;i;i-=i&-i)	res+=c[i];
	return res;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q,ch.resize(M);
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		int len=s1.size(),l,r;
		s1=" "+s1,s2=" "+s2;
		if(s1==s2)	continue;
		for(l=1;s1[l]==s2[l];l++);
		for(r=len;s1[r]==s2[r];r--);
		int u1=1,u2=2,u3=3,u4=4;
		for(int i=l;i<=r;i++){
			int t1=s1[i]-'a',t2=s2[i]-'a';
			if(!ch[u1][t1])	ch[u1][t1]=++cnt;
			if(!ch[u2][t2])	ch[u2][t2]=++cnt;
			u1=ch[u1][t1],u2=ch[u2][t2];
		}
		for(int i=l-1;i>=1;i--){
			int t=s1[i]-'a';
			if(!ch[u3][t])	ch[u3][t]=++cnt;
			u3=ch[u3][t];
		}
		for(int i=r+1;i<=len;i++){
			int t=s1[i]-'a';
			if(!ch[u4][t])	ch[u4][t]=++cnt;
			u4=ch[u4][t];
		}
		auto &g=mp[{u1,u2}];
		if(!g)	g=++tot;
		tx[g].push_back({u3,u4,0});
	}
	dfs(3),m=0,dfs(4);
	for(int i=1;i<=tot;i++){
		for(auto p:tx[i]){
			t[i].push_back({dfn[p[0]],0,dfn[p[1]],oud[p[1]],1});
			t[i].push_back({oud[p[0]]+1,0,dfn[p[1]],oud[p[1]],-1});
		}
	}
	for(int i=1;i<=q;i++){
		cin>>s1>>s2;
		if(s1.size()!=s2.size())	continue;
		int len=s1.size(),l,r;
		s1=" "+s1,s2=" "+s2;
		for(l=1;s1[l]==s2[l];l++);
		for(r=len;s1[r]==s2[r];r--);
		int u1=1,u2=2,u3=3,u4=4;
		for(int i=l;i<=r;i++){
			int t1=s1[i]-'a',t2=s2[i]-'a';
			u1=ch[u1][t1],u2=ch[u2][t2];
		}
		if(!mp.count({u1,u2}))	continue;
		for(int i=l-1;i>=1;i--){
			int t=s1[i]-'a';
			if(!ch[u3][t])	break;
			u3=ch[u3][t];
		}
		for(int i=r+1;i<=len;i++){
			int t=s1[i]-'a';
			if(!ch[u4][t])	break;
			u4=ch[u4][t];
		}
		t[mp[{u1,u2}]].push_back({dfn[u3],i,dfn[u4],0,0});
	}
	for(int i=1;i<=tot;i++){
		sort(t[i].begin(),t[i].end());
		for(auto p:t[i]){
			if(p[1]==0)	add(p[2],p[4]),add(p[3]+1,-p[4]);
			else	ans[p[1]]=query(p[2]);
		}
	}
	for(int i=1;i<=q;i++)	cout<<ans[i]<<'\n';
	return 0;
}
