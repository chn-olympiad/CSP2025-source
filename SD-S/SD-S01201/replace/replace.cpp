#include<bits/stdc++.h>
using namespace std;
namespace lkwbian{
	using ll=long long;
	using pii=pair<int,int>;
	#define fi first
	#define se second
	#define pb emplace_back
	const int N=200005;
	const int M=5000005;
	int n,q;
	int ans[N];
	struct rBIN{
		vector<array<int,26>>ch,hc;
		int op,po;
		vector<pii>vc;
		struct node{
			int x,y,id;
			node(int _x,int _y,int _id):x(_x),y(_y),id(_id){}
			inline bool operator < (const node B)const{
				return x>B.x;
			}
		};
		vector<node>cv;
		void add(string s,int l,int r){
			int p=0;
			for(int i=l-1,x;~i;--i){
				x=s[i]-'a';
				if(!ch[p][x]){
					ch[p][x]=++op;
					ch.pb(array<int,26>());
				}
				p=ch[p][x];
			}
			int q=0;
			for(int i=r+1,x;i<s.size();i++){
				x=s[i]-'a';
				if(!hc[q][x]){
					hc[q][x]=++po;
					hc.pb(array<int,26>());
				}
				q=hc[q][x];
			}
			vc.pb(p,q);
		}
		vector<int>in,out,L,R;
		int now;
		void dfs(int x){
			in[x]=++now;
			for(int i=0;i<26;i++){
				if(ch[x][i])dfs(ch[x][i]);
			}
			out[x]=now;
		}
		void fds(int x){
			L[x]=++now;
			for(int i=0;i<26;i++){
				if(hc[x][i])fds(hc[x][i]);
			}
			R[x]=now;
		}
		void init(){
			in.resize(ch.size()),out.resize(ch.size());
			L.resize(hc.size()),R.resize(hc.size());
			dfs(0);
			now=0;
			fds(0);
		}
		void dda(string s,int l,int r,int id){
			int p=0;
			for(int i=l-1,x;~i;i--){
				x=s[i]-'a';
				if(!ch[p][x])break;
				p=ch[p][x];
			}
			int q=0;
			for(int i=r+1,x;i<s.size();i++){
				x=s[i]-'a';
				if(!hc[q][x])break;
				q=hc[q][x];
			}
			cv.pb(in[p],L[q],id);
		}
		struct mdf{
			int l,r,x;
			mdf(int _l,int _r,int _x):l(_l),r(_r),x(_x){}
			inline bool operator < (const mdf B)const{
				return x>B.x;
			}
		};
		struct BIT{
			vector<int>c;
			int lm;
			void init(int t){
				c=vector<int>(t+5,0);
				lm=t;
			}
			inline void add(int l,int r){
				for(l=lm-l+1;l<=lm;l+=l&-l)--c[l];
				for(r=lm-r+1;r<=lm;r+=r&-r)++c[r];
			}
			inline int query(int x){
				int ans=0;
				for(x=lm-x+1;x;x&=x-1)ans+=c[x];
				return ans;
			}
		}ds;
		void solve(){
			vector<mdf>B;
			for(auto P:vc){
				int u=P.fi,v=P.se;
				int a=in[u],b=out[u],c=L[v],d=R[v];
				B.pb(d,c-1,a-1);B.pb(c-1,d,b);
			}
			sort(B.begin(),B.end());
			sort(cv.begin(),cv.end());
			ds.init(now);
			int j=0;
			for(int i=0;i<cv.size();i++){
				while(j<B.size() and B[j].x>=cv[i].x){
					ds.add(B[j].l,B[j].r);
					++j;
				}
				ans[cv[i].id]=ds.query(cv[i].y);
			}
		}
		void prework(){
			op=po=now=0;
			ch.resize(1),hc.resize(1);
		}
	}T[N];
	int cnt;
	map<pii,int>mp;
	const int mod=1e9+7;
	void Main(){
		cin.tie(nullptr)->sync_with_stdio(0);
		cin>>n>>q;
		for(int i=1;i<=n;i++){
			string s,t;
			cin>>s>>t;
			if(s==t)continue;
			int op=s.size(),l,r;
			for(int j=0;j<op;j++){
				if(s[j]^t[j]){
					l=j;break;
				}
			}
			for(int j=op-1;~j;j--){
				if(s[j]^t[j]){
					r=j;break;
				}
			}
			int val=0,lav=0;
			for(int j=l;j<=r;j++)
				val=(233ll*val+s[j])%mod;
			for(int j=l;j<=r;j++)
				lav=(233ll*lav+t[j])%mod;
			auto lll=make_pair(val,lav);
			if(!mp[lll]){
				mp[lll]=++cnt;
				T[cnt].prework();
			}
			T[mp[lll]].add(s,l,r);
		}
		for(int i=1;i<=cnt;i++)T[i].init();
		for(int i=1;i<=q;i++){
			string s,t;
			cin>>s>>t;
			int op=s.size(),l,r;
			for(int j=0;j<op;j++){
				if(s[j]^t[j]){
					l=j;break;
				}
			}
			for(int j=op-1;~j;j--){
				if(s[j]^t[j]){
					r=j;break;
				}
			}
			int val=0,lav=0;
			for(int j=l;j<=r;j++)
				val=(233ll*val+s[j])%mod;
			for(int j=l;j<=r;j++)
				lav=(233ll*lav+t[j])%mod;
			auto lll=make_pair(val,lav);	
			if(!mp[lll])continue;
			T[mp[lll]].dda(s,l,r,i);
		}
		for(int i=1;i<=cnt;i++)T[i].solve();
		for(int i=1;i<=q;i++)cout<<ans[i]<<'\n';
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	lkwbian::Main();
	return 0;
}
//Ren5Jie4Di4Ling5% 
// A: 17min 
// B: 1h11min, 15:58
