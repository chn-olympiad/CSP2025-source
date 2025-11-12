#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define mkpr make_pair
#define x first
#define y second
const int maxn=2e5+5;
const int maxm=5e6+5;
const int Z=26;
int n,m,N;
string s[maxn][2];
string t[maxn][2];
int len[maxn];
struct Node{
	map<int,int> ch;
	int fail,len,cnt;
}D[maxm];
int tot;
vector<int> T[maxm];
inline int id(int x,int y){return x*Z+y;}
inline void insert(string &s1,string &s2){
	int l=s1.size(),u=0;
	for(int i=0;i<l;i++){
		int c1=s1[i]-'a',c2=s2[i]-'a',c=id(c1,c2);
		if(!D[u].ch.count(c)) D[u].ch[c]=++tot;
		u=D[u].ch[c];
	}
	D[u].len=l,D[u].cnt++;
}
int fd(int u,int c){
	if(!u||D[u].ch.count(c)) return D[u].ch[c];
	return D[u].ch[c]=fd(D[u].fail,c);
}
void getfail(){
	queue<int> q;
	for(pii p:D[0].ch){
		int u=p.y;
		q.push(u);
	}
	while(!q.empty()){
		int u=q.front();q.pop();
		T[D[u].fail].push_back(u);
		for(pii p:D[u].ch){
			int c=p.x,v=p.y;
			D[v].fail=fd(D[u].fail,c);
			q.push(v);
		}
	}
}
int c[maxm];
inline void add(int x,int k){for(;x;x-=x&-x)c[x]+=k;}
inline int qry(int x){int s=0;for(;x<=N;x+=x&-x)s+=c[x];return s;}
vector<pii> Aq[maxm];
ll ans[maxn];
void dfs(int u){
	if(D[u].len) add(D[u].len,D[u].cnt);
	for(pii p:Aq[u]) ans[p.x]+=qry(p.y);
	for(int v:T[u]) dfs(v);
	if(D[u].len) add(D[u].len,-D[u].cnt);
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		insert(s[i][0],s[i][1]);
	}
	getfail();
	for(int i=1;i<=m;i++){
		cin>>t[i][0]>>t[i][1];
		if(t[i][0].size()!=t[i][1].size()) continue;
		len[i]=t[i][0].size();
		int u=0,l=0,r=len[i]-1;
		while(l<len[i]&&t[i][0][l]==t[i][1][l]) l++;
		while(r>=0&&t[i][0][r]==t[i][1][r]) r--;
		for(int j=0;j<len[i];j++){
			int c1=t[i][0][j]-'a',c2=t[i][1][j]-'a',c=id(c1,c2);
			u=fd(u,c);
			if(j>=r) Aq[u].push_back(mkpr(i,j-l+1));
		}
		N=max(N,len[i]);
	}
	dfs(0);
	for(int i=1;i<=m;i++) cout<<ans[i]<<'\n';
	// cerr<<1.0*clock()/CLOCKS_PER_SEC<<'\n';
	return 0;
}