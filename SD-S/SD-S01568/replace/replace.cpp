#include<bits/stdc++.h>
using namespace std;
const int N=2.5e6+10,M=2e5+10;
struct ACAM{
	int son[N][26],fail[N],cnt,pos[N],dfn[N],ed[N],len[N],tot,p;
	vector<int>e[N];
	void insert(const string &s,int id){
		int p=0;
		for(auto i:s){
			int c=i-'a';
			if(!son[p][c]){
				son[p][c]=++cnt;
				len[son[p][c]]=len[p]+1;
			}
			p=son[p][c];
		}
		pos[id]=p;
	}
	void dfs(int u){
		dfn[u]=++tot;
		for(auto v:e[u])
			dfs(v);
		ed[u]=tot;
	}
	void build(){
		queue<int>q;
		for(int i=0;i<26;i++)
			if(son[0][i])
				q.push(son[0][i]);
		while(!q.empty()){
			auto u=q.front();
			q.pop();
			for(int i=0;i<26;i++){
				if(son[u][i]){
					fail[son[u][i]]=son[fail[u]][i];
					q.push(son[u][i]);
				}
				else
					son[u][i]=son[fail[u]][i];
			}
		}
		for(int i=1;i<=cnt;i++)
			e[fail[i]].push_back(i);
		dfs(0);
	}
	void extend(char c){
		p=son[p][c-'a'];
	}
	void limit(int l){
		while(len[p]>=l)
			p=fail[p];
	}
}t1,t2;
struct BIT{
	int s[N];
	void add(int x,int k){
		while(x<N){
			s[x]+=k;
			x+=x&-x;
		}
	}
	int query(int x){
		int res=0;
		while(x){
			res+=s[x];
			x-=x&-x;
		}
		return res;
	}
	void add(int l,int r,int x){
		add(l,x);
		add(r+1,-x);
	}
}t;
int n,m,cnt;
long long ans[M];
vector<array<int,3>> add[N],q[N];
string s0,s1;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s0>>s1;
		t1.insert(s0,i);
		t2.insert(s1,i);
	}
	t1.build();
	t2.build();
	for(int i=1;i<=n;i++){
		int l0=t1.dfn[t1.pos[i]],r0=t1.ed[t1.pos[i]];
		int l1=t2.dfn[t2.pos[i]],r1=t2.ed[t2.pos[i]];
		add[l0].push_back({l1,r1,1});
		add[r0+1].push_back({l1,r1,-1});
	}
	for(int i=1;i<=m;i++){
		cin>>s0>>s1;
		int posl=1e9,posr=-1;
		for(int j=0;j<(int)s0.size();j++)
			if(s0[j]!=s1[j]){
				posl=min(posl,j);
				posr=max(posr,j);
			}
//		cout<<posl<<" "<<posr<<endl;
		t1.p=t2.p=0;
		for(int j=0;j<(int)s0.size();j++){
			t1.extend(s0[j]);
			t2.extend(s1[j]);
			if(j>=posr)
				q[t1.dfn[t1.p]].push_back({t2.dfn[t2.p],i,1});
		}
		t1.p=t2.p=0;
		for(int j=0;j<(int)s0.size();j++){
			t1.extend(s0[j]);
			t2.extend(s1[j]);
			if(j>=posr){
				t1.limit(j-posl+1);
				t2.limit(j-posl+1);
//				cout<<t1.p<<" "<<t2.p<<endl;
//				cout<<t1.len[9]<<endl;
				q[t1.dfn[t1.p]].push_back({t2.dfn[t2.p],i,-1});
			}
		}
	}
	for(int i=1;i<N;i++){
		for(auto it:add[i])
			t.add(it[0],it[1],it[2]);
		for(auto it:q[i])
			ans[it[1]]+=t.query(it[0])*it[2];
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<'\n';
	return 0;
}
