#include<bits/stdc++.h>
using namespace std;
bool mbs;
#define ull unsigned long long
const ull base=307;
const ull mod=11000000000616307;
const int maxn=5e6+20;
struct node{int x,y,len;ull las,now,val;}a[maxn];
inline ull get(string s,int l,int r){ull res=0;for(int i=l;i<=r;i++) res=(res*base+s[i]);return res;}
inline node get(string &s,string &t){
	s=" "+s,t=" "+t;node res;res.len=s.size()-1;
	int n=res.len;
	int l=1,r=n;
	while(l<=n&&s[l]==t[l]) l++;
	while(r&&s[r]==t[r]) r--;
	res.x=l-1,res.y=n-r;
	res.las=get(s,l,r),res.now=get(t,l,r),res.val=get(s,1,n);
	return res;
}
map<pair<ull,ull>,int> mp;
vector<node> rec[maxn];
string s,t;
int n,q,tot;
ull mul[maxn];
namespace subtask1{
	ull pre[maxn];
	node now;
	inline ull calc(int l,int r){return (pre[r]-pre[l-1]*mul[r-l+1]);}
	inline void solve(){
		while(q--){
			cin>>s>>t;
			if(s.size()!=t.size()){cout<<0<<'\n';continue;}
			now=get(s,t);
			int m=now.len,ans=0;
			for(int i=1;i<=m;i++) pre[i]=(pre[i-1]*base+s[i]);
			int cur=mp[{now.las,now.now}];
			for(node zyzh:rec[cur]){
				if(zyzh.x>now.x||zyzh.y>now.y) continue;
				int k=now.x+1-zyzh.x;
				if(calc(k,k+zyzh.len-1)==zyzh.val) ans++;
			}
			cout<<ans<<'\n';
		}
	}
}
inline int check(string s){
	int len=s.size()-1,cnt=0;
	for(int i=1;i<=len;i++) if(s[i]=='b') cnt++;
	return cnt==1;
}
namespace subtask2{
	struct segment_tree{
		int idx=0;
		struct tr{int val,l,r;}tree[maxn<<3];
		#define ls(p) tree[p].l
		#define rs(p) tree[p].r
		#define push_up(p) tree[p].val=tree[ls(p)].val+tree[rs(p)].val
		void update(int &p,int l,int r,int x){
			if(!p) p=++idx;
			if(l==r) return tree[p].val++,void();
			int mid=l+r>>1;
			if(x<=mid) update(ls(p),l,mid,x);
			else update(rs(p),mid+1,r,x);
			push_up(p);
		}
		int query(int p,int l,int r,int x,int y){
			if(!p) return 0;
			if(x<=l&&r<=y) return tree[p].val;
			int mid=l+r>>1;
			if(y<=mid) return query(ls(p),l,mid,x,y);
			if(x>mid) return query(rs(p),mid+1,r,x,y);
			return query(ls(p),l,mid,x,y)+query(rs(p),mid+1,r,x,y);
		}
	}S;
	int rt[maxn],tmp;
	map<pair<int,int>,int> kkk;
	vector<int> id[maxn];
	inline void solve(){
		for(int i=1;i<=n;i++){
			int x=mp[{a[i].las,a[i].now}];
			if(!kkk[{x,a[i].x}]) kkk[{x,a[i].x}]=++tmp;
			S.update(rt[kkk[{x,a[i].x}]],1,5000000,a[i].len);
		}node now;
		while(q--){
			cin>>s>>t;
			if(s.size()!=t.size()){cout<<0<<'\n';continue;}
			now=get(s,t);if(!check(s)||!check(t)){cout<<0<<'\n';continue;}
			int m=now.len,ans=0,pos,cur=mp[{now.las,now.now}];
			for(int i=1;i<=now.x+1;i++){
				pos=kkk[{cur,now.x-i+1}];
				ans+=S.query(rt[pos],1,5000000,(m-now.y)-i+1,m-i+1);
			}
			cout<<ans<<'\n';
		}
	}
}
bool mbt;
int main(){
//	cerr<<(&mbs-&mbt)/1024.0/1024.0<<endl;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	mul[0]=1;
	for(int i=1;i<=5000000;i++) mul[i]=(mul[i-1]*base);
	cin>>n>>q;int flag=1;
	for(int i=1;i<=n;i++){
		cin>>s>>t;
		if(s==t){i--,n--;continue;}
		a[i]=get(s,t);
		if(!mp[{a[i].las,a[i].now}]) mp[{a[i].las,a[i].now}]=++tot;
		rec[mp[{a[i].las,a[i].now}]].push_back(a[i]);
		flag&=check(s)&check(t);
	}
	if(flag) subtask2::solve();
	else subtask1::solve();
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/