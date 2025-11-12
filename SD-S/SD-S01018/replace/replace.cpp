#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using i128=__int128;
using ull=unsigned long long;
//bool f1;
namespace SOLVE{
	const int N=2e5+5,K=5e6+5;
	int n,q;
	string s[N][2],t[N][2];
	int sn[N],tn[N],psl[N],psr[N],ptl[N],ptr[N];
	ll hss[N],hst[N];
	ll mod=1e17+13,c=31;
	ll hs[2*N],h;
	struct trie1{
		int nt[K][28],x[K*2],cnt;
		int rt;
		void build(){
			rt=++cnt;
		}
		void ps(string &s,int i,int w){
			int p=rt,sz=s.length();
			for(;i<sz;i++){
				if(nt[p][s[i]-'a'+1]==0) nt[p][s[i]-'a'+1]=++cnt;
				p=nt[p][s[i]-'a'+1];
			}
			x[p]+=w;
		}
		int q(string &s,int i){
			int ans=x[rt],p=rt,sz=s.length();
			for(;i<sz;i++){
				if(nt[p][s[i]-'a'+1]==0) break;
				p=nt[p][s[i]-'a'+1];ans+=x[p];
			}
			return ans;
		}
	}tr;
	int nt1[N],nt2[N];
	int pnt[K+N][28],cnt;
	int rt[N],x1[K+N],x2[K+N];
	int ans[N];
	vector<int> fnt[K+N];
	void dfs(int u){
		int xx=x1[u];
		while(xx){
			tr.ps(s[xx][0],psr[xx]+1,1);
			xx=nt1[xx];
		}
		xx=x2[u];
		while(xx){
			ans[xx]=tr.q(t[xx][0],ptr[xx]+1);
			xx=nt2[xx];
		}
		for(auto i:fnt[u]) dfs(pnt[u][i]);
		xx=x1[u];
		while(xx){
			tr.ps(s[xx][0],psr[xx]+1,-1);
			xx=nt1[xx];
		}
	}
	void main(){
		ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		cin>>n>>q;
		for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
		for(int i=1;i<=q;i++) cin>>t[i][0]>>t[i][1];
		for(int i=1;i<=n;i++){
			sn[i]=s[i][0].length();
			psl[i]=sn[i];psr[i]=-1;
			for(int j=0;j<sn[i];j++) if(s[i][0][j]!=s[i][1][j]){
				psl[i]=j;break;
			}
			for(int j=sn[i]-1;j>=0;j--) if(s[i][0][j]!=s[i][1][j]){
				psr[i]=j;break;
			}
			if(psl[i]>psr[i]) continue;
			ll now=0;
			for(int j=psl[i];j<=psr[i];j++){
				now=(now*c+s[i][0][j]-'a'+1)%mod;
				now=(now*c+s[i][1][j]-'a'+1)%mod;
			}
			hss[i]=now;hs[++h]=now;
		}
		for(int i=1;i<=q;i++){
			tn[i]=t[i][0].length();
			ptl[i]=tn[i];ptr[i]=-1;
			for(int j=0;j<tn[i];j++) if(t[i][0][j]!=t[i][1][j]){
				ptl[i]=j;break;
			}
			for(int j=tn[i]-1;j>=0;j--) if(t[i][0][j]!=t[i][1][j]){
				ptr[i]=j;break;
			}
			ll now=0;
			for(int j=ptl[i];j<=ptr[i];j++){
				now=(now*c+t[i][0][j]-'a'+1)%mod;
				now=(now*c+t[i][1][j]-'a'+1)%mod;
			}
			hst[i]=now;hs[++h]=now;
		}
		sort(hs+1,hs+h+1);h=unique(hs+1,hs+h+1)-hs-1;
		for(int i=1;i<=n;i++) hss[i]=lower_bound(hs+1,hs+h+1,hss[i])-hs;
		for(int i=1;i<=q;i++) hst[i]=lower_bound(hs+1,hs+h+1,hst[i])-hs;
		tr.build();cnt=h;
		for(int i=1;i<=h;i++) rt[i]=i;
		for(int i=1;i<=n;i++){
			int p=rt[hss[i]];
			for(int j=psl[i]-1;j>=0;j--){
				if(pnt[p][s[i][0][j]-'a'+1]==0){
					pnt[p][s[i][0][j]-'a'+1]=++cnt;
					fnt[p].emplace_back(s[i][0][j]-'a'+1);
				}
				p=pnt[p][s[i][0][j]-'a'+1];
			}
			nt1[i]=x1[p];
			x1[p]=i;
		}
		for(int i=1;i<=q;i++){
			int p=rt[hst[i]];
			for(int j=ptl[i]-1;j>=0;j--){
				if(pnt[p][t[i][0][j]-'a'+1]==0) break;
				p=pnt[p][t[i][0][j]-'a'+1];
			}
			nt2[i]=x2[p];
			x2[p]=i;
		}
		for(int i=1;i<=h;i++) dfs(rt[i]);
		for(int i=1;i<=q;i++) printf("%d\n",ans[i]);
	}
}
//bool f2;
int main(){
//	int _=clock();
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int T=1;
	while(T--) SOLVE::main();
//	cerr<<((&f2)-(&f1))/1024.0/1024.0<<endl;
//	cerr<<clock()-_<<endl;
	return 0;
}
