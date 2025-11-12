#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define fi first
#define se second
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(z);x>=(y);x--)
#define eb emplace_back
#define emp emplace
#define pob pop_back
#define tomx(x,y) x=max(x,y)
#define tomn(x,y) x=min(x,y)
#define pof pop_front
#define ull unsigned long long
#define beg begin
#define all(x) beg(x),end(x)
#define allt(x,y,z) beg(x)+y,beg(x)+z
using namespace std;
/*
被做局了，我现在会 L1 log^2 +nq.没有任何分 

暴力：枚举要替换的区间，一共 sqrt(L1)L2个。 

O(L2*sqrt(L1)*(log)+q*sqrt(L1))

监考不让在外面随机游走。草 

这个铃声好诡异。 
*/
int n,q;
#define N 200008
#define mod 2000000063
//#define mod 998244353
#define base 127
int L1,L2,pw[1000006];
#define debug(x) cerr<<"line="<<__LINE__<<" the "#x<<" is "<<(x)<<"\n";
string s[N][2],t[N][2];
#define mkp make_pair
namespace sub1{
	bool check(){
		return max(L1,L2)<=2005;
	}
	vi v;
	int h[N][2],hsh[2][N];
	vpii g[N];
	int cnt(pii x,int len){
		return upper_bound(all(g[len]),x)-lower_bound(all(g[len]),x);
	}
	void solve(){
//		return;
		pw[0]=1;
		rep(i,1,1000006-1) pw[i]=pw[i-1]*base%mod;
		rep(i,1,n){
			v.eb((int)s[i][0].size());
		}
		sort(all(v));
		v.erase(unique(all(v)),end(v));
		rep(i,1,n){
			int l=s[i][0].size();
			s[i][0]=" "+s[i][0];
			s[i][1]=" "+s[i][1];
			rep(j,1,l){
				h[i][0]=(h[i][0]*base+s[i][0][j])%mod;
				h[i][1]=(h[i][1]*base+s[i][1][j])%mod;
			}
			g[l].eb(mkp(h[i][0],h[i][1]));
//			debug(i);
//			debug(l);
//			debug(h[i][0]);
//			debug(h[i][1]);
		}
		for(int i:v) sort(all(g[i]));
		rep(iq,1,q){
			int l=t[iq][0].size();
			int a=0,b=0;
			t[iq][0]=" "+t[iq][0];
			t[iq][1]=" "+t[iq][1];
//			debug(iq);
//			debug(l);
			rep(i,1,l){
				if(t[iq][0][i]!=t[iq][1][i]){
					if(!a) a=i;
					b=i;
				}
			}
			int ans=0;
//			debug(a);
//			debug(b);
			rep(i,1,l){
				hsh[0][i]=(hsh[0][i-1]*base+t[iq][0][i])%mod;
				hsh[1][i]=(hsh[1][i-1]*base+t[iq][1][i])%mod;
			}
			#define gt(hs,l,r) (int)(((hs[r]-hs[l-1]*pw[(r)-(l)+1])%mod+mod)%mod) 
			for(int&len:v){
//				debug(len);debug(b-len+1);debug(a);
				rep(i,b-len+1,a){
					if(i<=0) continue;
					if(i+len-1>l) continue;
//					debug(i);
//					debug(gt(hsh[0],i,i+len-1));
//					debug(gt(hsh[1],i,i+len-1)); 
//					cerr<<"\n";
					ans+=cnt(mkp(gt(hsh[0],i,i+len-1),gt(hsh[1],i,i+len-1)),len);
				}
//				cerr<<"\n----\n";
			}
			cout<<ans<<"\n";
		}
	}
	
}
namespace sub2{
	bool bet(const string&s){
		return (count(all(s),'a')+1==(int)s.size())&&(count(all(s),'b')==1);
	}
	bool check(){
		rep(i,1,n){
			if(!bet(s[i][0])) return 0;
			if(!bet(s[i][1])) return 0;
		}
		rep(i,1,q){
			if(!bet(t[i][0])) return 0;
			if(!bet(t[i][1])) return 0;
		}
		return 1;
	}
	struct node{
		int len,x,y;
		int id;
//		int xs
		node(int _len,int _x,int _y,int _id){
			x=_x;
			len=_len;
			y=_y;
			id=_id;
		}
	};
	vector<node> e;
	#define V 5000005
	int tm[V*2];
	int ans[N];
	int c[V*2];
	#define lowbit(x) ((x)&-(x))
	void add(int p,int x,int t){
		for(p+=V-1;p<2*V;p+=lowbit(p)){
			if(t^tm[p]){
				tm[p]=t;
				c[p]=0;
			}
			c[p]+=x;
		}
	}
	int ask(int p,int t){
		int x=0;
		for(p+=V-1;p;p-=lowbit(p)){
			if(t^tm[p]){
				tm[p]=t;
				c[p]=0;
			}
			x+=c[p];
		}
		return x;
	}
	void solve(){
		rep(i,1,n){
			int l=s[i][0].size();
			s[i][0]=" "+s[i][0];
			s[i][1]=" "+s[i][1];
			int a=0,b=0;
			rep(j,1,l){
				if(s[i][0][j]=='b') a=j;
			}
			rep(j,1,l){
				if(s[i][1][j]=='b') b=j;
			}
			e.eb(b-a+1,min(a,b)-1,l-max(a,b),-i);
		}
		rep(iq,1,q){
			int l=t[iq][0].size();
			t[iq][0]=" "+t[iq][0];
			t[iq][1]=" "+t[iq][1];
			int a=0,b=0;
			rep(j,1,l){
				if(t[iq][0][j]=='b') a=j;
			}
			rep(j,1,l){
				if(t[iq][1][j]=='b') b=j;
			}
			e.eb(b-a+1,min(a,b)-1,l-max(a,b),iq);
		}
//		int pre=INT_MAX;
		sort(all(e),[&](node a,node b){
			if(a.len^b.len) return a.len<b.len;
			if(a.x^b.x) return a.x<b.x;
			return a.id<b.id;
		});
		for(node&p:e){
			int len=p.len;
			int x=p.x;
			int y=p.y;
			int id=p.id;
			if(id<0){
				add(y,1,len);
			}else{
				ans[id]+=ask(y,len);
			}
		}
		rep(i,1,q) cout<<ans[i]<<"\n";
	}
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
//	return 0;
	rep(i,1,n){
		cin>>s[i][0]>>s[i][1];
		L1+=s[i][0].size();
		L1+=s[i][1].size();
	}
	rep(i,1,q){
		cin>>t[i][0]>>t[i][1];
		L2+=t[i][0].size();
		L2+=t[i][1].size();
	}
	if(sub2::check()) sub2::solve();
	else sub1::solve();
}
/*
4 1
xabcx xadex
ab cd
bc de
aa bb
aaaa bbbb
*/

