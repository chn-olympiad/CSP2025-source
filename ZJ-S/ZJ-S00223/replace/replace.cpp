#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define lep(i,l,r) for(int i=(l);i>=(r);--i)
//#define int long long
#define pii pair<int,int>
#define endl '\n'
#define pb push_back
#define fi first
#define se second

const int N=2.5e6+5;
const int M=2e5;
const long long bs=233;
const int mod=998244353;

int n,q;
pair<string,string> a[M],b[M];
vector<int> L;map<int,bool> mpl;
map<pii,bool> mp;
struct node{
	int p1,p2,len,l;
}p[M];
map<pii,vector<node> >mb;

int h1[N],h2[N],fac[N];

int POW(int A,int B){
	int res=1;for(;B;B>>=1,A=1ll*A*A%mod)if(B&1)res=1ll*res*A%mod;return res;
}

void solver_008(){
	cin>>n>>q;
	rep(i,1,n)cin>>a[i].fi>>a[i].se;
	rep(i,1,q){
		cin>>b[i].fi>>b[i].se;
		int len=b[i].fi.size();
		int l,r;
		rep(j,0,len-1)if(b[i].fi[j]!=b[i].se[j]){l=j;break;}
		lep(j,len-1,0)if(b[i].fi[j]!=b[i].se[j]){r=j;break;}
		if(!mpl.count(r-l+1))L.pb(r-l+1),mpl[r-l+1]=1;
		int p1=0,p2=0;
		rep(j,l,r)p1=(p1*bs+b[i].fi[j]-'a'+1)%mod;
		rep(j,l,r)p2=(p2*bs+b[i].se[j]-'a'+1)%mod;
		p[i]={p1,p2,r+1,l+1};mp[make_pair(p1,p2)]=1;
	}
	fac[0]=1;rep(i,1,M-5)fac[i]=fac[i-1]*bs%mod;
	sort(L.begin(),L.end());
	int qwq=L.size();
	rep(i,1,n){
		int len=a[i].fi.size();
		rep(j,0,len)h1[j]=h2[j]=0;
		rep(j,1,len)h1[j]=(h1[j-1]*bs+a[i].fi[j-1]-'a'+1)%mod;
		rep(j,1,len)h2[j]=(h2[j-1]*bs+a[i].se[j-1]-'a'+1)%mod;
		rep(j,1,len){
			rep(k,0,qwq-1)if(j+L[k]-1<=len){
				int ln=L[k];
				int p1=(h1[j+ln-1]-h1[j-1]*1ll*fac[ln]%mod+mod)%mod;
				int p2=(h2[j+ln-1]-h2[j-1]*1ll*fac[ln]%mod+mod)%mod;
				if(mp.count(make_pair(p1,p2))){
					node tmp={h1[len],h2[len],len,j-1};
					mb[make_pair(p1,p2)].pb(tmp);
				}
			}
		}
	}
	rep(i,1,q){
		int ans=0;
		int len=b[i].fi.size();
		rep(j,0,len)h1[j]=h2[j]=0;
		rep(j,1,len)h1[j]=(h1[j-1]*bs+b[i].fi[j-1]-'a'+1)%mod;
		rep(j,1,len)h2[j]=(h2[j-1]*bs+b[i].se[j-1]-'a'+1)%mod;
		pii pp=make_pair(p[i].p1,p[i].p2);
		int lll=mb[pp].size();
		rep(k,0,lll-1){
			node tmp=mb[pp][k];
			int l=p[i].l-tmp.l,r=l+tmp.len-1;
			if(l>0&&r<=len){
				int p1=(h1[r]-h1[l-1]*1ll*fac[r-l+1]%mod+mod)%mod;
				int p2=(h2[r]-h2[l-1]*1ll*fac[r-l+1]%mod+mod)%mod;
				if(p1==tmp.p1&&p2==tmp.p2)ans++;
			}
		}
		cout<<ans<<endl;
	}
}

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int __T=1;
	while(__T--){
		solver_008();
	}
	return 0;
}
