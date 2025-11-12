#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const ull B=1333331,P=998244353;
const int N=5e6+5;
ull gethash(const string &s,int l,int r){
	ull hsh=0;
	for(int i=l;i<=r;i++)
		hsh=(hsh*B+ull(s[i]-'a'+1));
	return hsh;
}
ull getpairhash(ull a,ull b){
	return a*B*B+b;
}
struct DiscreteUnit{
	int bkt[N],bt;
	void clear(){bt=0;}
	void push(int x){bkt[++bt]=x;}
	void discr(){
		sort(bkt+1,bkt+1+bt);
		bt=unique(bkt+1,bkt+1+bt)-bkt-1;
	}
	int query(int x){
		return lower_bound(bkt+1,bkt+1+bt,x)-bkt;
	}
}dcr;
struct Trie{
	struct Node{
		int son[26],dfnL,dfnR;
	}t[N];
	int root,tot;
	void Insert(string &s){
		int cur=root;
		for(char c:s){
			if(!t[cur].son[c-'a'])
				t[cur].son[c-'a']=++tot;
			cur=t[cur].son[c-'a'];
		}
	}
	int tim;
	void dfs(int x){
		t[x].dfnL=++tim;
		for(int i=0;i<26;i++) if(t[x].son[i])
			dfs(t[x].son[i]);
		t[x].dfnR=tim;
	}
	pair<int,int> seek_range(string &s){
		int cur=root;
		for(char c:s){
			cur=t[cur].son[c-'a'];
		}
		return make_pair(t[cur].dfnL,t[cur].dfnR);
	}
	int seek_pos(string &s){
		int cur=root;
		for(char c:s){
			cur=t[cur].son[c-'a'];
		}
		return t[cur].dfnL;
	}
}pre,suf;
struct SegmentTree{
	struct Node{
		int add;
	}t[N<<2];
	#define ls(p) (p<<1)
	#define rs(p) (p<<1|1)
	void Apply(int p,int v){
		t[p].add+=v;
	}
	void Spread(int p){
		Apply(ls(p),t[p].add),Apply(rs(p),t[p].add);
		t[p].add=0;
	}
	void Build(int p,int l,int r){
		t[p].add=0;
		if(l==r) return;
		int mid=(l+r)/2;
		Build(ls(p),l,mid),Build(rs(p),mid+1,r);
	}
	void RA(int p,int l,int r,int L,int R,int v){
		if(L<=l and r<=R) return Apply(p,v);
		int mid=(l+r)/2;Spread(p);
		if(L<=mid) RA(ls(p),l,mid,L,R,v);
		if(R>mid)  RA(rs(p),mid+1,r,L,R,v);
	}
	int PQ(int p,int l,int r,int x){
		if(l==r) return t[p].add;
		int mid=(l+r)/2;Spread(p);
		if(x<=mid) return PQ(ls(p),l,mid,x);
		else return PQ(rs(p),mid+1,r,x);
	}
}t;
const int M=2e5+5;
string getrp(string &s,int p){
	string ss;
	for(int i=0;i<p;i++) ss.push_back(s[i]);
	reverse(ss.begin(),ss.end());
	return ss;
}
string getsf(string &s,int p){
	string ss;
	for(int i=p+1;i<s.length();i++) ss.push_back(s[i]);
	return ss;
}
struct SP{
	string s1,s2,rp,sf;
	int lp,rpp,n;
	ull Prework(){
		n=s1.length();
		for(lp=0;lp<n;lp++) if(s1[lp]!=s2[lp]) break;
		for(rpp=n-1;rpp>=0;rpp--) if(s1[rpp]!=s2[rpp]) break;
		rp=getrp(s1,lp),sf=getsf(s1,rpp);
		return getpairhash(gethash(s1,lp,rpp),gethash(s2,lp,rpp));
	}
}mdf[M],qry[M];
int ans[N],n,q;
unordered_map<ull,vector<int>> mdfm,qrym;
struct Line{
	int l,r,op;
};
vector<Line> vec[N];vector<pair<int,int>> qvc[N];
void PerSolve(vector<int> &mf,vector<int> &qr){
	dcr.clear();
	for(int i:mf){
		auto p=pre.seek_range(mdf[i].rp);
		dcr.push(p.first),dcr.push(p.second);
		p=suf.seek_range(mdf[i].sf);
		dcr.push(p.first),dcr.push(p.second);
	}
	for(int i:qr){
		auto p=pre.seek_pos(qry[i].rp);
		dcr.push(p);
		p=suf.seek_pos(qry[i].sf);
		dcr.push(p);
	}
	dcr.discr();
	for(int i=1;i<=dcr.bt;i++) vec[i].clear(),qvc[i].clear();
	for(int i:mf){
		auto p=pre.seek_range(mdf[i].rp);
		auto p2=suf.seek_range(mdf[i].sf);
		int l=dcr.query(p2.first);
		int r=dcr.query(p2.second);
		vec[dcr.query(p.first)].push_back(Line{l,r,1});
		vec[dcr.query(p.second)+1].push_back(Line{l,r,-1});
	}
	for(int i:qr){
		auto p=pre.seek_pos(qry[i].rp);
		auto p2=suf.seek_pos(qry[i].sf);
		qvc[dcr.query(p)].emplace_back(i,dcr.query(p2));
	}

	t.Build(1,1,dcr.bt);
	for(int i=1;i<=dcr.bt;i++){
		for(Line ln:vec[i]) t.RA(1,1,dcr.bt,ln.l,ln.r,ln.op);
		for(auto ln:qvc[i])
			ans[ln.first]=t.PQ(1,1,dcr.bt,ln.second);
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr);
	//1277MB, acceptable
//	cerr<<(sizeof(pre)+sizeof(suf)+sizeof(t)+sizeof(dcr))/1024/1024<<" MB\n";
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>mdf[i].s1>>mdf[i].s2;
		if(mdf[i].s1==mdf[i].s2) continue;
		ull hsh=mdf[i].Prework();
		mdfm[hsh].push_back(i);
		pre.Insert(mdf[i].rp),suf.Insert(mdf[i].sf);
	}
	for(int i=1;i<=q;i++){
		cin>>qry[i].s1>>qry[i].s2;
		ull hsh=qry[i].Prework();
		qrym[hsh].push_back(i);
		pre.Insert(qry[i].rp),suf.Insert(qry[i].sf);
	}
	pre.dfs(pre.root),suf.dfs(suf.root);
	for(auto i:qrym){
//		for(int j:i.second){
//			if(j==13){
//				cerr<<"Q "<<qry[j].s1<<" "<<qry[j].s2<<"\n";
//				cerr<<"\n";
//				cerr<<"CDT "<<mdfm[i.first].size()<<"\n";
//				for(int kj:mdfm[i.first])
//					if(mdf[kj].n<=qry[j].n)
//						cerr<<mdf[kj].s1<<" "<<mdf[kj].s2<<"\n";
//			}
//		}
		PerSolve(mdfm[i.first],i.second);
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<"\n";
	return 0;
}
/*FOOTNOTE
*/
