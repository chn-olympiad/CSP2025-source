#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define rep(i,j,k) for(int i=j;i<=k;++i)
#define per(i,j,k) for(int i=j;i>=k;--i)
int const N=1.2e7+10,M=2e5+10,mod1=998244353,mod2=1e9+7;
int n,q,idx,mp[26],ans[M],I1[M],I2[M],J1[M],J2[M],ch[N][26],L[N],R[N];
mt19937 rnd(time(0));
map< pair<int,int>,int >gp;
inline int insert(int x,string y){
	for (auto i:y){
		if (!ch[x][i-'a']) ch[x][i-'a']=++idx;
		x=ch[x][i-'a'];
	}
	return x;
}
inline void dfs(int x){
	L[x]=++L[0];
	rep(i,0,25) if (ch[x][i]) dfs(ch[x][i]);
	R[x]=L[0];
}
struct Tree_Array{
	#define lowbit(x) ((x)&(-x))
	int c[N];
	inline void update(int x,int v){
		while (x<N) c[x]+=v,x+=lowbit(x);
	}
	inline void update(int l,int r,int v){
		update(l,v),update(r+1,-v);
	}
	inline int query(int x){
		int res=0;
		while (x) res+=c[x],x-=lowbit(x);
		return res;
	}
}T;
struct node1{int tim,l,r,v;};
struct node2{int tim,p,id;};
inline void solve(){
	cin>>n>>q;
	rep(i,0,25) mp[i]=rnd();
	rep(p,1,n){
		string s1,s2;cin>>s1>>s2;
		int sz=s1.size(),i=-1,j=sz;
		string pre="",suf="";
		while (i+1<j && s1[i+1]==s2[i+1]) ++i;
		while (i+1<j && s1[j-1]==s2[j-1]) --j;
		int hsh1=0,hsh2=0;
		rep(t,i+1,j-1) hsh1=(hsh1*233ll+mp[s1[t]-'a'])%mod1,hsh2=(hsh2*233ll+mp[s1[t]-'a'])%mod2;
		rep(t,i+1,j-1) hsh1=(hsh1*233ll+mp[s2[t]-'a'])%mod1,hsh2=(hsh2*233ll+mp[s1[t]-'a'])%mod2;
		if (!gp.count({hsh1,hsh2})) gp[{hsh1,hsh2}]=++idx,++idx;
		per(t,i,0) pre+=s1[t];
		rep(t,j,sz-1) suf+=s1[t];
		I1[p]=insert(gp[{hsh1,hsh2}],pre);
		I2[p]=insert(gp[{hsh1,hsh2}]+1,suf);
	}
	rep(p,1,q){
		string s1,s2;cin>>s1>>s2;
		int sz=s1.size(),i=-1,j=sz;
		string pre="",suf="";
		while (i+1<j && s1[i+1]==s2[i+1]) ++i;
		while (i+1<j && s1[j-1]==s2[j-1]) --j;
		int hsh1=0,hsh2=0;
		rep(t,i+1,j-1) hsh1=(hsh1*233ll+mp[s1[t]-'a'])%mod1,hsh2=(hsh2*233ll+mp[s1[t]-'a'])%mod2;
		rep(t,i+1,j-1) hsh1=(hsh1*233ll+mp[s2[t]-'a'])%mod1,hsh2=(hsh2*233ll+mp[s1[t]-'a'])%mod2;
		if (!gp.count({hsh1,hsh2})) gp[{hsh1,hsh2}]=++idx,++idx;
		per(t,i,0) pre+=s1[t];
		rep(t,j,sz-1) suf+=s1[t];
		J1[p]=insert(gp[{hsh1,hsh2}],pre);
		J2[p]=insert(gp[{hsh1,hsh2}]+1,suf);
	}
	rep(i,1,idx) if (!L[i]) dfs(i);
	vector<node1>ad;vector<node2>ak;
	rep(i,1,n){
		ad.push_back({L[I1[i]],L[I2[i]],R[I2[i]],1});
		ad.push_back({R[I1[i]]+1,L[I2[i]],R[I2[i]],-1});
	}
	rep(i,1,q)
		if (J1[i]) ak.push_back({L[J1[i]],L[J2[i]],i});
	sort(all(ad),[](node1 x,node1 y){return x.tim<y.tim;});
	sort(all(ak),[](node2 x,node2 y){return x.tim<y.tim;});
	int e=0;
	for (auto it:ak){
		while (e<(int)ad.size() && ad[e].tim<=it.tim)
			T.update(ad[e].l,ad[e].r,ad[e].v),++e;
		ans[it.id]=T.query(it.p);
	}
	rep(i,1,q) cout<<ans[i]<<'\n';
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t=1;
	while (t--) solve();
	return 0;
}