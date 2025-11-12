#include<bits/stdc++.h>
#define pii pair<int,int>
#define mkp make_pair
#define pb push_back
using namespace std;
const int maxn=200005,maxm=5000005;
int N,Q;
string a[maxn],b[maxn],c[maxn],d[maxn];
vector<int> S1[maxm],S2[maxm],S[maxm];
int trie[maxm][26],tot=1;
void ins(string s,int id){
	int x=1;
	for(char i:s){
		if(!trie[x][i-'a']) trie[x][i-'a']=++tot;
		x=trie[x][i-'a'];
	}
	S1[x].pb(id);
}
int ans[maxn],dfn[maxm],out[maxm],T_in;
void dfs(int x){
	dfn[x]=++T_in;
	for(int i=0;i<26;i++) if(trie[x][i]) dfs(trie[x][i]);
	out[x]=T_in;
}
int val[maxn],pl[maxn],pr[maxn],h[maxn];
void dfs2(int x,vector<pii> cur,int dep){
	if(S[x].size()){
		int len=cur.size();
		for(int i=0;i<len;i++) h[i]=0;
		for(int i:S[x]){
			int l=pl[i],r=pr[i];
			for(int j=0;j<len;j++)
			 if(l<=cur[j].first&&cur[j].first<=r) ans[cur[j].second]++;
		}
	}
	vector<pii> l[26];
	for(auto i:cur){
		if(dep>=c[i.second].size()) continue;
		// cerr<<dep<<' '<<c[i.second].size()<<'\n';
		// cerr<<c[i.second][dep]<<'\n';
		l[c[i.second][dep]-'a'].pb(i);
	}
	for(int i=0;i<26;i++) if(trie[x][i]) dfs2(trie[x][i],l[i],dep+1);
}
void solve(int p){
	// puts("----");
	// for(int i:S1[p]) printf("%d ",i);puts("");
	// for(int i:S2[p]) printf("%d ",i);puts("");
	for(int i=1;i<=tot;i++) memset(trie[i],0,sizeof trie[i]);tot=1;T_in=0;
	for(int i:S2[p]){
		int x=1;
		for(char j:d[i]){
			if(!trie[x][j-'a']) trie[x][j-'a']=++tot;
			x=trie[x][j-'a'];
		}
	}
	dfs(1);
	vector<pii> cur;
	for(int i:S2[p]){
		int x=1;
		for(char j:d[i]) x=trie[x][j-'a'];
		val[i]=dfn[x];
		cur.pb(mkp(val[i],i));
		// printf("S2: %d %d\n",i,val[i]);
	}
	sort(cur.begin(),cur.end());
	for(int i:S1[p]){
		int x=1;
		for(char j:b[i]) x=trie[x][j-'a'];
		pl[i]=dfn[x];pr[i]=out[x];
		// printf("S1: %d %d %d\n",i,pl[i],pr[i]);
	}
	for(int i=1;i<=tot;i++) memset(trie[i],0,sizeof trie[i]);tot=1;S[1].clear();
	for(int i:S2[p]){
		int x=1;
		for(char j:c[i]){
			if(!trie[x][j-'a']) trie[x][j-'a']=++tot,S[tot].clear();
			x=trie[x][j-'a'];
		}
	}
	for(int i:S1[p]){
		int x=1;
		for(char j:a[i]) x=trie[x][j-'a'];
		if(x&&pr[i]) S[x].pb(i);
	}
	dfs2(1,cur,0);
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin>>N>>Q;
	for(int i=1;i<=N;i++) {
		string p,q;cin>>p>>q;
		int l=0,r=p.size()-1;
		while(p[l]==q[l]) l++;
		while(p[r]==q[r]) r--;
		string s;
		for(int j=l;j<=r;j++) s+=p[j],s+=q[j];
		for(int j=l-1;j>=0;j--) a[i]+=p[j];
		for(int j=r+1;j<p.size();j++) b[i]+=p[j];
		ins(s,i);
	}
	for(int i=1;i<=Q;i++) {
		string p,q;cin>>p>>q;
		if(p.size()!=q.size())continue;
		int l=0,r=p.size()-1;
		while(p[l]==q[l]) l++;
		while(p[r]==q[r]) r--;
		int x=1;
		for(int j=l;j<=r;j++){
			x=trie[x][p[j]-'a'];
			x=trie[x][q[j]-'a'];
		}
		if(!x)continue;
		for(int j=l-1;j>=0;j--) c[i]+=p[j];
		for(int j=r+1;j<p.size();j++) d[i]+=q[j];
		S2[x].pb(i);
	}
	int ed=tot;
	for(int p=1;p<=ed;p++) if(S1[p].size()&&S2[p].size()) solve(p);
	for(int i=1;i<=Q;i++) cout<<ans[i]<<'\n';
	return 0;
}