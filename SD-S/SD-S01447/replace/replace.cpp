#include<bits/stdc++.h>
using namespace std;
#define re(i,n) for(int i=1;i<=n;i++)
#define pe(i,n) for(int i=n;i>=1;i--)
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,r,l) for(int i=r;i>=l;i--)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
#define mkp make_pair
#define fi first
#define se second
#define pb push_back
#define CIOO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define lowbit(x) (x & -x)
#define ls(x) lson[x]
#define rs(x) rson[x]
bool Beg;
const int N=2e5+5,NL=5e6+5;
int n,Q;
string s1[N],s2[N];
int len[N];
int pos1[N],pos2[N];
struct ACAM{
	int ch[NL][26],fail[NL];
	vector<int> ed[NL];
	int L[NL],R[NL];
	int ncnt;
	int insert(string s,int id){
		int now=0;
		for(char c:s){
			if(!ch[now][c-'a']){
				ch[now][c-'a']=++ncnt;
			}
			now=ch[now][c-'a'];
		}
		ed[now].pb(id);
		return now;
	}
	vector<int> G[NL];
	int dfncnt;
	void dfs(int u){
		L[u]=++dfncnt;
		for(int v:G[u]){
			dfs(v);
		}
		R[u]=dfncnt;
	}
	void build(){
		queue<int> q;
		rep(c,0,25){
			if(ch[0][c])q.push(ch[0][c]);
		}
		while(!q.empty()){
			int u=q.front();
			q.pop();
			rep(c,0,25){
				if(!ch[u][c]){
					ch[u][c]=ch[fail[u]][c];
				}
				else{
					fail[ch[u][c]]=ch[fail[u]][c];
					q.push(ch[u][c]);
				}
			}
		}
		re(i,ncnt)G[fail[i]].pb(i);
		dfs(0);
	}
}ac1,ac2;
struct Qry{
	int x,y,l,id;
};
int qcnt;
Qry qy[NL];
struct Op{
	int l1,r1,l2,r2,l;
};
Op ops[N];
bool cmp1(Qry x,Qry y){
	return x.l>y.l;
}
bool cmp2(Op x,Op y){
	return x.l>y.l;
}
ll Ans[N];
namespace dt2{
	int t[N*46],lson[N*46],rson[N*46];
	int ntot;
	void modify(int &rt,int l,int r,int ml,int mr){
		if(!rt)rt=++ntot;
		if(ml<=l&&r<=mr){
			t[rt]++;
			return;
		}
		int mid=(l+r)/2;
		if(ml<=mid)modify(ls(rt),l,mid,ml,mr);
		if(mr>mid)modify(rs(rt),mid+1,r,ml,mr);
	}
	int query(int rt,int l,int r,int p){
		if(!rt)return 0;
		if(l==r)return t[rt];
		int mid=(l+r)/2;
		if(p<=mid)return query(ls(rt),l,mid,p)+t[rt];
		return query(rs(rt),mid+1,r,p)+t[rt];
	}
}
namespace dt{
	int t[NL*4];
	void modify(int rt,int l,int r,int ml,int mr,int xl,int xr){
		if(ml<=l&&r<=mr){
			dt2::modify(t[rt],1,ac2.ncnt,xl,xr);
			return;
		}
		int mid=(l+r)/2;
		if(ml<=mid)modify(rt*2,l,mid,ml,mr,xl,xr);
		if(mr>mid)modify(rt*2+1,mid+1,r,ml,mr,xl,xr);
	}
	int query(int rt,int l,int r,int p,int q){
		int res=dt2::query(t[rt],1,ac2.ncnt,q);
		if(l==r)return res;
		int mid=(l+r)/2;
		if(p<=mid)res+=query(rt*2,l,mid,p,q);
		else res+=query(rt*2+1,mid+1,r,p,q);
		return res;
	}
}
bool End;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	CIOO;
	cin>>n>>Q;
	re(i,n)cin>>s1[i]>>s2[i];
	re(i,n)len[i]=s1[i].size();
	re(i,n)pos1[i]=ac1.insert(s1[i],i);
	re(i,n)pos2[i]=ac2.insert(s2[i],i);
	ac1.build();
	ac2.build();
	re(iq,Q){
		string t1,t2;
		cin>>t1>>t2;
		int u=0,v=0;
		int sz=t1.size();
		int lcp=0,lcs=0;
		while(lcp<sz){
			if(t1[lcp]==t2[lcp])lcp++;
			else break;
		}
		while(lcs<sz){
			if(t1[sz-lcs-1]==t2[sz-lcs-1])lcs++;
			else break;
		}
		lcp--;
		lcs=sz-lcs;
		rep(i,0,sz-1){
			u=ac1.ch[u][t1[i]-'a'];
			v=ac2.ch[v][t2[i]-'a'];
			if(i>=lcs-1){
				qy[++qcnt]=(Qry){ac1.L[u],ac2.L[v],i-lcp,iq};
//				re(j,n){
//					if((ac1.L[pos1[j]]<=ac1.L[u]&&ac1.L[u]<=ac1.R[pos1[j]])&&
//					(ac2.L[pos2[j]]<=ac2.L[v]&&ac2.L[v]<=ac2.R[pos2[j]])){
//						if(len[j]>=i-lcp)ans++;
//					}
//				}
			}
		}
	}
	re(i,n){
		ops[i].l1=ac1.L[pos1[i]];
		ops[i].r1=ac1.R[pos1[i]];
		ops[i].l2=ac2.L[pos2[i]];
		ops[i].r2=ac2.R[pos2[i]];
		ops[i].l=len[i];
	}
//	re(i,qcnt){
//		re(j,n){
//			if(ops[j].l1<=qy[i].x&&qy[i].x<=ops[j].r1&&ops[j].l2<=qy[i].y&&qy[i].y<=ops[j].r2&&qy[i].l<=ops[j].l){
//				Ans[qy[i].id]++;
//			}
//		}
//	}
	sort(qy+1,qy+qcnt+1,cmp1);
	sort(ops+1,ops+n+1,cmp2);
	int cur=0;
	re(i,qcnt){
		while(cur<n&&ops[cur+1].l>=qy[i].l){
			cur++;
			dt::modify(1,1,ac1.ncnt,ops[cur].l1,ops[cur].r1,ops[cur].l2,ops[cur].r2);
		}
		Ans[qy[i].id]+=dt::query(1,1,ac1.ncnt,qy[i].x,qy[i].y);
	}
	re(i,Q)cout<<Ans[i]<<'\n';
	return 0;
}
