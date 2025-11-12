#include<bits/stdc++.h>
#define maxn 1010001
#define fi first
#define se second
#define int long long
using namespace std;
mt19937 yrand(time(0));
const int Mod=1e9+7,inf=1e9+7,N=1e7;
typedef long long ll;
int reduce(int x){return x-(x>=Mod)*Mod;}

const int Bas=yrand()%(Mod-4)+2;
int n,m,id[maxn],ans[maxn],pos[maxn][2],tmp[maxn];
pair<int,int>lm[maxn];
string a[maxn][2];
struct BIT{
	int t[N+100];
	void update(int x,int k){
		for(int i=x;i<=N;i+=i&-i) t[i]+=k;
	}
	int query(int x){
		int res=0;
		for(int i=x;i;i-=i&-i) res+=t[i];
		return res;
	}
}B;
struct Trie{
	signed ch[N+100][26];
	int dfn[N+100],siz[N+100],cnt;
	pair<int,int>id[maxn];
	int tot,head[N+100];
	void init(){
		for(int i=0;i<=cnt;i++) head[i]=0,memset(ch[i],0,sizeof(ch[i]));
		cnt=tot=0;
	}
	void insert1(string str,int num){
		int len=str.size(),u=0;
		for(int i=0;i<len;i++){
			int v=str[i]-'a';
			if(!ch[u][v]) ch[u][v]=++cnt;
			u=ch[u][v];
		}
		id[++tot]=make_pair(num,head[u]);
		head[u]=tot;
	}
	void dfs1(int x){
		for(int i=head[x];i;i=id[i].se){
			int cur=id[i].fi;
//			cerr<<cur<<' ';
			if(cur<=n){
				B.update(dfn[tmp[cur]],1);
				B.update(dfn[tmp[cur]]+siz[tmp[cur]],-1);
				continue;
			}
			ans[cur]=B.query(dfn[tmp[cur]]);
		}
		for(int i=0;i<26;i++)
		 if(ch[x][i]){
		 	dfs1(ch[x][i]);
		 }
		for(int i=head[x];i;i=id[i].se){
			int cur=id[i].fi;
			if(cur<=n){
				B.update(dfn[tmp[cur]],-1);
				B.update(dfn[tmp[cur]]+siz[tmp[cur]],1);
				continue;
			}
		}
	}
	void work1(){
		dfs1(0);
	}
	int insert(string str){
		int len=str.size(),u=0;
		for(int i=len-1;i>=0;i--){
			int v=str[i]-'a';
			if(!ch[u][v]) ch[u][v]=++cnt;
			u=ch[u][v];
		}
		return u;
	}
	void dfs(int x){
		dfn[x]=++cnt,siz[x]=1;
		for(int i=0;i<26;i++)
		 if(ch[x][i]){
		 	dfs(ch[x][i]),siz[x]+=siz[ch[x][i]];
		 }
	}
	void work(){
		cnt=0;
		dfs(0);
	}
}T;
void work(int l,int r){
	if(!lm[id[l]].fi) return;
//	cerr<<"Current: "<<l<<' '<<r<<'\n';
	T.init();
	for(int it=l;it<=r;it++){
		int i=id[it];
//		cerr<<i<<' ';
		tmp[i]=T.insert(a[i][0].substr(0,pos[i][0]));
	}
	T.work();
	T.init();
//	cerr<<'\n';
	for(int it=l;it<=r;it++){
		int i=id[it];
//		cerr<<T.dfn[tmp[i]]<<' '<<T.dfn[tmp[i]]+T.siz[tmp[i]]-1<<'\n';
		T.insert1(a[i][0].substr(pos[i][1]+1,(int)a[i][0].size()-pos[i][1]-1),i);
	}
	T.work1();
//	cerr<<'\n';
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1];
		id[i]=i;
		int len=a[i][0].size();
		pos[i][0]=0,pos[i][1]=len-1;
		while(pos[i][0]<len&&a[i][0][pos[i][0]]==a[i][1][pos[i][0]]) pos[i][0]++;
		if(pos[i][0]==len) continue;
		while(pos[i][1]>=0&&a[i][0][pos[i][1]]==a[i][1][pos[i][1]]) pos[i][1]--;
		lm[i].fi=pos[i][1]-pos[i][0]+1;
		int res=0;
		for(int j=pos[i][0];j<=pos[i][1];j++) res=(res*Bas+(a[i][0][j]-'a'+1))%Mod;
		for(int j=pos[i][0];j<=pos[i][1];j++) res=(res*Bas+(a[i][1][j]-'a'+1))%Mod;
		lm[i].se=res;
	}
	for(int i=n+1;i<=n+m;i++){
		cin>>a[i][0]>>a[i][1];
		id[i]=i;
		int len=a[i][0].size(),len1=a[i][1].size();
		if(len!=len1) continue;
		pos[i][0]=0,pos[i][1]=len-1;
		while(pos[i][0]<len&&a[i][0][pos[i][0]]==a[i][1][pos[i][0]]) pos[i][0]++;
		assert(pos[i][0]!=len);
		while(pos[i][1]>=0&&a[i][0][pos[i][1]]==a[i][1][pos[i][1]]) pos[i][1]--;
		lm[i].fi=pos[i][1]-pos[i][0]+1;
		int res=0;
		for(int j=pos[i][0];j<=pos[i][1];j++) res=(res*Bas+(a[i][0][j]-'a'+1))%Mod;
		for(int j=pos[i][0];j<=pos[i][1];j++) res=(res*Bas+(a[i][1][j]-'a'+1))%Mod;
		lm[i].se=res;
	}
	sort(id+1,id+n+m+1,[](int x,int y){
		if(lm[x]==lm[y]) return x>y;
		return lm[x]<lm[y];
	});
	for(int i=1;i<=n+m;i){
		int j=i;
		while(j<=n+m&&lm[id[i]]==lm[id[j]]) j++;
		work(i,j-1);
		i=j;
	}
	for(int i=1;i<=m;i++) cout<<ans[n+i]<<'\n';
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
//	init();
	int T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}
