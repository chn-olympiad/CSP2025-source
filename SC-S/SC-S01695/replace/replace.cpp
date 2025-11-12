#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define cmax(a,b) ((a)=max((a),(b)))
#define cmin(a,b) ((a)=min((a),(b)))
#define pb emplace_back
#define ull unsigned long long
using namespace std;
const int N=2e5+10,M=5e6+10;
const ull base=917120411;
ull pw[M],bac[M+N],*hs[N];
int n,q,id[N];
inline ull get_hash(ull *hs,int l,int r){return hs[r]-hs[l-1]*pw[r-l+1];}
unordered_map<ull,int> mp;
struct node{string s1,s2;}rep[N];
struct qry{
	string t1,t2;
	int l,r;
	void init(){
		l=t1.length(),r=0;
		for(int i=0;i<(int)t1.length();++i)
			if(t1[i]!=t2[i])cmin(l,i),cmax(r,i);
	}
}Q[N];
int ans[N];
ull Hash(node &p){
	int len=p.s1.length();
	ull res=0;
	for(int i=0;i<len;++i)
		res=res*base+(p.s1[i]*200+p.s2[i]);
	return res;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i)cin>>rep[i].s1>>rep[i].s2;
	iota(id+1,id+1+n,1);
	sort(id+1,id+1+n,[](int x,int y){
		return rep[x].s1.length()<rep[y].s1.length();	
	});
	for(int i=1;i<=q;++i){
		cin>>Q[i].t1>>Q[i].t2;
		Q[i].t1=" "+Q[i].t1;
		Q[i].t2=" "+Q[i].t2;
		Q[i].init();
	}
	pw[0]=1;
	for(int i=1;i<M;++i)pw[i]=pw[i-1]*base;
	for(int cur=0,i=1;i<=q;++i){
		hs[i]=bac+(++cur);
		int len=Q[i].t1.length()-1;
		for(int j=1;j<=len;++j)
			hs[i][j]=hs[i][j-1]*base+(Q[i].t1[j]*200+Q[i].t2[j]);
		cur+=len;
	}
	for(int l=1,r=1;l<=n;){
		mp.clear();
		while(r<n&&rep[id[r+1]].s1.length()==rep[id[l]].s1.length())++r;
		while(l<=r)++mp[Hash(rep[id[l++]])];
		++r;
		int L=rep[id[l-1]].s1.length();
		for(int i=1;i<=q;++i){
			int p=min((int)(Q[i].t1.length()-1),Q[i].l+L-1);
			for(int j=max(Q[i].r,L);j<=p;++j){
				ull k=get_hash(hs[i],j-L+1,j);
				if(mp.count(k))ans[i]+=mp[k];
			}
		}
	}
	for(int i=1;i<=q;++i)cout<<ans[i]<<'\n';
	return 0;
}