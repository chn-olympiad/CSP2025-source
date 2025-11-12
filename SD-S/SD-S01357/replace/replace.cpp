//Ren5Jie4Di4Ling5%
#include<bits/stdc++.h>
//#define int long long
#define rep(x,y,z) for(int x=y;x<=z;++x)
#define per(x,z,y) for(int x=z;x>=y;--x)
#define qwq cout<<'\n'
#define exq exit(0)
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
#define pb push_back
using namespace std;
void IOS(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
}
void Document(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
}
using ull=unsigned long long;
bool sta__;
const int N=2e5+55;
const int M=5e6+55;
int n,q;
struct as{
	string x,z;
	ull has1;
	ull has2;
	int len;
	int id;// 0 s1,s2 12345 t1 t2
	bool operator <(const as&it) const {
		if(len!=it.len) return len<it.len;
		if(has1==it.has1) return has2<it.has2;
		return has1<it.has1;
	}
	bool operator ==(const as&it) const {
		if(len!=it.len) return false;
		if(has1!=it.has1) return false;
		return has2==it.has2;
	}
}re[N*2];
int tot;
int answer[N];
string aa,bb;
void add(int id){
	cin>>aa;
	cin>>bb;
	int len=aa.size();
	int enl=bb.size();
	if(enl!=len) return;
	int L=len+1;
	int R=0;
	rep(i,1,len){
		if(aa[i-1]!=bb[i-1]){
			cmin(L,i);
			cmax(R,i);
		}
	}
	ull has1=0;
	ull has2=0;
	rep(i,L,R){
		has1*=13331;
		has1+=(aa[i-1]-'a'+1);
		has2*=13331;
		has2+=(bb[i-1]-'a'+1);
	}
	tot++;
	re[tot].id=id;
	re[tot].has1=has1;
	re[tot].has2=has2;
	re[tot].len=R-L+1;
	string x,z;
	per(i,L-1,1) x=x+aa[i-1];
	rep(i,R+1,len) z=z+bb[i-1];
	re[tot].x=x;
	re[tot].z=z;
//	cout<<aa<<' '<<bb;
//	qwq;
//	cout<<x<<' '<<z;
//	qwq;
//	cout<<has1<<' '<<has2;
//	qwq;
//	cout<<L<<' '<<R;
//	qwq;
//	cout<<id<<' '<<len;
//	qwq;
}
struct tr1{
	int son[28];
	bool sz;
	vector<int> en;
}t1[M];
struct tr2{
	int son[28];
	int en;
}t2[M];
int idtot;
void inse(string s,int ix){
	int len=s.size();
	int u=1;
	if(re[ix].id>0) t1[u].sz=1;
	rep(i,1,len){
		int v=s[i-1]-'a'+1;
		if(!t1[u].son[v]) t1[u].son[v]=++idtot;
		u=t1[u].son[v];
		if(re[ix].id>0) t1[u].sz=1;
	}
	t1[u].en.pb(ix);
}
int itt=1;
void insert(string s){
	int len=s.size();
	int u=1;
	rep(i,1,len){
		int v=s[i-1]-'a'+1;
		if(!t2[u].son[v]) t2[u].son[v]=++itt;
		u=t2[u].son[v];
	}
	t2[u].en++;
}
void delt(string s){
	int len=s.size();
	int u=1;
	rep(i,1,len){
		int v=s[i-1]-'a'+1;
		u=t2[u].son[v];
	}
	t2[u].en--;
}
int shouge(string s){
	int u=1;
	int res=0;
	int len=s.size();
	res+=t2[u].en;
	rep(i,1,len){
		int v=s[i-1]-'a'+1;
		if(!t2[u].son[v]) break;
		u=t2[u].son[v];
		res+=t2[u].en;
	}
	return res;
}
void dfs(int u){
	for(int v:t1[u].en){
		if(re[v].id==0) insert(re[v].z);
	}
	for(int v:t1[u].en){
		if(re[v].id!=0){
			answer[re[v].id]=shouge(re[v].z);
		}
	}
	rep(i,1,26){
		if(t1[u].son[i]) if(t1[t1[u].son[i]].sz) dfs(t1[u].son[i]);
	}
	for(int v:t1[u].en){
		if(re[v].id==0) delt(re[v].z);
	}
}
void solve(int l,int r){
//	if(l==r) return;
	bool op=0;
	rep(i,l,r) if(re[i].id>0) op=1;
	if(!op) return;
	rep(i,1,idtot){
		t1[i].en.clear();
		t1[i].sz=0;
		rep(o,0,26) t1[i].son[o]=0;
	}
	idtot=1;
	rep(i,l,r) inse(re[i].x,i);
	dfs(1);
}
bool end__;
main(){
	IOS();
	Document();
//	cerr<<(&sta__-&end__)/1000/1000;
	cin>>n>>q;
	rep(i,1,n) add(0);
	rep(i,1,q) add(i);
	sort(re+1,re+1+tot);
//	exq;
	rep(i,1,tot){
//		cout<<re[i].x<<' '<<re[i].len<<' '<<re[i].z<<' ';
//		cout<<re[i].id<<' '<<re[i].has1<<' '<<re[i].has2;
//		qwq;
//		continue;
		int o=i;
		for(;o+1<=tot&&re[i]==re[o+1];++o);
		solve(i,o);
		i=o;
	}
	rep(i,1,q) cout<<answer[i]<<'\n';
	return 0;
}
