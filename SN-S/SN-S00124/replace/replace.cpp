#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int n,q;
bool bg;
namespace s1{
	const int maxn=2e5+15,maxs=5e6+15,bas=13331;
	string s1[maxn],s2[maxn],t1,t2;
	int ans;
	ull hsh1[maxn],hsh2[maxn],pw[maxs],h1[maxn],h2[maxn];
	ull gt1(int l,int r){return l>r?0:hsh1[r]-hsh1[l-1]*pw[r-l+1];}
	ull gt2(int l,int r){return l>r?0:hsh2[r]-hsh2[l-1]*pw[r-l+1];}
	signed main(){
		pw[0]=1;
		for(int i=1;i<maxs;i++) pw[i]=pw[i-1]*bas;
		for(int i=1;i<=n;i++){
			cin>>s1[i]>>s2[i];
			for(char c:s1[i]) h1[i]=h1[i]*bas+c;
			for(char c:s2[i]) h2[i]=h2[i]*bas+c;
		}
		while(q--){
			cin>>t1>>t2,ans=0;
			if(t1.size()!=t2.size()){
				cout<<"0\n";
				continue;
			}
			for(int i=0;i<(int)t1.size();i++) hsh1[i+1]=hsh1[i]*bas+t1[i];
			for(int i=0;i<(int)t2.size();i++) hsh2[i+1]=hsh2[i]*bas+t2[i];
			for(int i=1;i<=n;i++){
				int lenS=s1[i].size(),lenT=t1.size();
				for(int j=1;j<=lenT-lenS+1;j++){
					int l=j,r=j+lenS-1;
					if(gt1(1,l-1)==gt2(1,l-1)&&h1[i]==gt1(l,r)&&
					gt1(r+1,lenT)==gt2(r+1,lenT)&&h2[i]==gt2(l,r)) ++ans;
				}
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
}

namespace s2{
	const int maxn=2e5+15,maxs=2e6+15,bas=13331;
	int ans[maxn],c[maxs],dfn[maxn],low[maxn],tot;
	vector<int> upd[maxs];
	struct node{int x,f,id;};
	vector<node> que[maxs];
	ull hsh1[maxn],hsh2[maxn],pw[maxs];
	ull gt1(int l,int r){return hsh1[l]-hsh1[r+1]*pw[r-l+1];}
	ull gt2(int l,int r){return hsh2[l]-hsh2[r+1]*pw[r-l+1];}
	struct Trie{
		int ch[maxs][26],fa[25][maxs],tot;
		unordered_map<ull,int> mp;
		Trie(){tot=1;}
		int ins(const string &x){
			int p=1;
			for(char c:x){
				int v=c-'a';
				if(!ch[p][v]) ch[p][v]=++tot;
				p=ch[p][v];
			}
			return p;
		}
		void dfs(int u,int fth=0,ull hsh=0){
			fa[0][u]=fth;
			mp[hsh]=u;
			for(int i=1;i<25;i++) fa[i][u]=fa[i-1][fa[i-1][u]];
			for(int i=0;i<26;i++){
				if(ch[u][i]) dfs(ch[u][i],u,hsh*bas+i+'a');
			}
		}
		int kfa(int u,int k){
			for(int i=24;i>=0;i--){
				if(k>>i&1) u=fa[i][u];
			}
			return u;
		}
	}T1,T2;
	void add(int x,int v){
		for(int i=x;i<=T2.tot;i+=i&-i) c[i]+=v;
	}
	int query(int x){
		int res=0;
		for(int i=x;i;i-=i&-i) res+=c[i];
		return res;
	}
	void dfs1(int u){
		dfn[u]=++tot;
		for(int i=0;i<26;i++){
			if(T2.ch[u][i]) dfs1(T2.ch[u][i]);
		}
		low[u]=tot;
	}
	void dfs2(int u){
		for(int x:upd[u]){
			add(dfn[x],1);
			add(low[x]+1,-1);
		}
		for(auto x:que[u]){
			ans[x.id]+=x.f*query(dfn[x.x]);
		}
		for(int i=0;i<26;i++){
			if(T1.ch[u][i]) dfs2(T1.ch[u][i]);
		}
		for(int x:upd[u]){
			add(dfn[x],-1);
			add(low[x]+1,1);
		}
	}
	signed main(){
		ios::sync_with_stdio(0);
		cin.tie(0);
		pw[0]=1;
		for(int i=1;i<maxs;i++) pw[i]=pw[i-1]*bas;
		for(int i=1;i<=n;i++){
			string s1,s2;
			cin>>s1>>s2;
			reverse(s1.begin(),s1.end());
			reverse(s2.begin(),s2.end());
			upd[T1.ins(s1)].push_back(T2.ins(s2));
		}
		T1.dfs(1);
		T2.dfs(1);
		for(int id=1;id<=q;id++){
			string t1,t2;
			cin>>t1>>t2;
			t1=" "+t1,t2=" "+t2;
			if(t1.size()!=t2.size()){
				cout<<"0\n";
				continue;
			}
			int len=t1.size()-1;
			for(int i=len;i>=1;i--){
				hsh1[i]=hsh1[i+1]*bas+t1[i];
				hsh2[i]=hsh2[i+1]*bas+t2[i];
			}
			int pre=0,suf=0;
			while(pre<len&&t1[pre+1]==t2[pre+1]) ++pre;
			while(suf<len&&t1[len-suf]==t2[len-suf]) ++suf;
			for(int i=max(1,len-suf);i<=len;i++){
				int L=1,R=i,res=0;
				while(L<=R){
					int mid=(L+R)>>1;
					if(T1.mp.count(gt1(mid,i))&&T2.mp.count(gt2(mid,i))){
						res=mid,R=mid-1;
					}
					else L=mid+1;
				}
				if(res>pre+1) continue;
				int x=T1.mp[gt1(res,i)],y=T2.mp[gt2(res,i)];
				que[x].push_back((node){y,1,id});
				x=T1.kfa(x,pre-res+2);
				y=T2.kfa(y,pre-res+2);
				if(x) que[x].push_back((node){y,-1,id});
			}
		}
		dfs1(1);
		dfs2(1);
		for(int i=1;i<=q;i++) cout<<ans[i]<<'\n';
		return 0;
	}
}
bool ed;

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	if(n<=1000) return s1::main();
	return s2::main();
}
