// thanks for 2048MB

#include <bits/stdc++.h>
using namespace std;

inline int read() {
	int x=0,ch=getchar();
	for(;!isdigit(ch);ch=getchar()) ;
	for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+(ch&15);
	return x;
}

using nt=const int&;
const int N=2e5+5,L=2.5e6+5;
int n,qnum; vector<int> reg[L];
char str[2][L];

// Trie
const int S=2.5e6+5;
int ch[2][26][S],tot[2]={1,1},failtp[2][S],ld[S];
inline void insert(nt k,int& now,char o) {
	if(!ch[k][o][now]) {
		ch[k][o][now]=++tot[k];
		if(k) ld[tot[k]]=ld[now]+1;
	}
	return void(now=ch[k][o][now]);
}
inline void build(nt k) {
	queue<int> que;
	for(int i=0;i<26;i++)
		if(!ch[k][i][1]) ch[k][i][1]=1;
		else failtp[k][ch[k][i][1]]=1,que.emplace(ch[k][i][1]);
	while(!que.empty()) {
		int u=que.front(); que.pop();
		for(int i=0;i<26;i++) {
			int to=ch[k][i][failtp[k][u]];
			if(!ch[k][i][u]) ch[k][i][u]=to;
			else failtp[k][ch[k][i][u]]=to,que.emplace(ch[k][i][u]);
		}
	}
	return ;
}
int siz[2],dson[2][S];
vector<int> son[2][S];
inline void buildfailtree() {
	for(int k=0;k<2;k++) {
		for(int i=2;i<=tot[k];i++) ++dson[k][failtp[k][i]]; siz[k]=tot[k];
		for(int i=1;i<=siz[k];i++) son[k][i].reserve(dson[k][i]);
		for(int i=2;i<=tot[k];i++) son[k][failtp[k][i]].emplace_back(i);
	}
	return ;
}

using ll=long long;
ll ans[N];
struct Question {
	int id,vet,ln;
	Question(int id=0,int vet=0,int ln=0):id(id),vet(vet),ln(ln) {}
};
vector<Question> q[L];

const int LG=22;
int t[L],dfn[L],out[L],tim,f[LG][L],length;
inline int lowbit(nt x) {return x&-x;}
inline void update(int p,nt x) {
	for(;p<=length;p+=lowbit(p)) t[p]+=x;
	return ;
}
inline int query(int p) {
	int tmp=0;
	for(;p;p-=lowbit(p)) tmp+=t[p];
	return tmp;
}
inline void modify(nt l,nt r,nt x) {
	return update(l,x),update(r+1,-x),void();
}
inline void predfs(nt u) {
	dfn[u]=++tim;
	for(int i=1;i<LG;i++) f[i][u]=f[i-1][f[i-1][u]];
	for(int v:son[1][u]) f[0][v]=u,predfs(v);
	return void(out[u]=tim);
}
inline int calculate(nt u,nt ln) {
	int v=u;
	for(int j=LG-1;~j;j--) if(ld[f[j][v]]>ln) v=f[j][v];
	return query(dfn[u])-query(dfn[f[0][v]]);
}
inline void solve(nt u) {
	for(int k:reg[u]) modify(dfn[k],out[k],1);
	for(auto ask:q[u]) ans[ask.id]+=calculate(ask.vet,ask.ln);
	for(int v:son[0][u]) solve(v);
	for(int k:reg[u]) modify(dfn[k],out[k],-1);
	return ;
}

bool flag[N];
inline int readstrings() {
	int ln1=0,ln2=0,ch=getchar();
	while(!isalpha(ch)) ch=getchar();
	for(;isalpha(ch);ch=getchar()) str[0][++ln1]=ch-'a';
	while(!isalpha(ch)) ch=getchar();
	for(;isalpha(ch);ch=getchar()) str[1][++ln2]=ch-'a';
	if(ln1!=ln2) return 0;
	return ln1;
}

int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),qnum=read();
	for(int i=1;i<=n;i++) {
		int ln=readstrings(),u=1,v=1;
		for(int i=ln;i;i--) insert(0,u,str[0][i]),insert(1,v,str[1][i]);
		reg[u].emplace_back(v);
	}
	build(0),build(1),buildfailtree(),predfs(1),length=siz[1];
	for(int i=1;i<=qnum;i++) {
		int ln=readstrings(),u=1,v=1,k=0;
		if(!ln) continue ;
		flag[0]=1;
		for(int j=1;j<=ln;j++) flag[j]=flag[j-1]&&(str[0][j]==str[1][j]);
		for(int j=ln;j;j--) {
			u=ch[0][str[0][j]][u],v=ch[1][str[1][j]][v];
			if(!k&&str[0][j]!=str[1][j]) k=j;
			if(flag[j-1]&&u>1&&v>1&&ld[v]>k-j) q[u].emplace_back(i,v,k-j);
		}
	}
	solve(1);
	for(int i=1;i<=qnum;i++) printf("%lld\n",ans[i]);
	return 0;
}

// 17:50
