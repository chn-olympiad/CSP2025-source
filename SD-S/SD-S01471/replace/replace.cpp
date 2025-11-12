#include<bits/stdc++.h>
using namespace std;
#define vec vector
#define pb push_back
#define eb emplace_back
#define siz(a) (int)((a).size())
#define all(a) (a).begin(),(a).end()
#define pii pair<int,int>
#define x first
#define y second
#define mp make_pair
#define exc(expr) if(expr)continue;
#define stop(expr) if(expr)break;
#define ret(expr) if(expr)return;
#define deb(var) cerr<<#var<<'='<<(var)<<"; "
#define debl(var) cerr<<#var<<'='<<(var)<<";\n"
#define inf (long long)(1e9)
#define ll long long
//#define int long long
template<class T>bool Min(T &x,T y){return x>y?x=y,1:0;}
template<class T>bool Max(T &x,T y){return x<y?x=y,1:0;}
const int mod=998244353;
void Add(int &x,int y){x=x+y<mod?x+y:x+y-mod;}
int fpm(int x,int y){
	int ans=1;for(;y;y>>=1,(x*=x)%=mod)if(y&1)(ans*=x)%=mod;return ans;
}

int n,q;
string a[200010],b[200010],qs[200010],qt[200010];
int lp[200010],rp[200010],lq[200010],rq[200010];
//#define ull unsigned long long
map<ll,vec<int> > vc;
int tot;
signed tr[10000010][26];
//vec<int> lk[10000010];
int head[10000010];
int nex[400010];
void clear(){
	while(tot){
		memset(tr[tot],0,sizeof tr[tot]);head[tot]=0;--tot;
	}
	memset(tr[0],0,sizeof tr[0]);
	head[0]=0;
}
void Ins(string str,int id){
	int u=0;
	for(auto ch:str){
		int c=ch-'a';
		if(!tr[u][c])tr[u][c]=++tot;
		u=tr[u][c];
	}
	nex[id]=head[u];
	head[u]=id;
}
int tim,dfn[400010],siz[400010];
int dfs(int u){
	int s=0;
	if(head[u]){
		++s;++tim;
		for(int v=head[u];v;v=nex[v])dfn[v]=tim;
	}
	for(int i=0;i<26;i++){
		int v=tr[u][i];
		if(v)s+=dfs(v);
	}
	for(int v=head[u];v;v=nex[v])siz[v]=s;
	return s;
}
ll ans[200010];
struct BIT{
	int w[400010];
	void add(int i,int x){
		for(;i<=4e5;i+=i&(-i)){
			w[i]+=x;
		} 
	}
	int qry(int i){
		int ans=0;for(;i;i-=i&(-i))ans+=w[i];
		return ans;
	}
}bit;
void redfs(int u){
	for(int i=head[u];i;i=nex[i]){
		if(i<=n){
			bit.add(dfn[i],1);
			bit.add(dfn[i]+siz[i],-1);
		}
	} 
	for(int i=head[u];i;i=nex[i]){
		if(i>n){
			ans[i-n]=bit.qry(dfn[i]);
		}
	} 
	for(int i=0;i<26;i++){
		int v=tr[u][i];
		if(v)redfs(v);
	}
	for(int i=head[u];i;i=nex[i]){
		if(i<=n){
			bit.add(dfn[i],-1);
			bit.add(dfn[i]+siz[i],1);
		}
	} 
}
void solve(vec<int> S){
	clear(); 
	for(auto i:S){
		string str="";
		if(i>0){
			for(int j=lp[i]-1;j>=0;j--)str.pb(a[i][j]);
			Ins(str,i);
		}else{
			i=-i;
			for(int j=lq[i]-1;j>=0;j--)str.pb(qs[i][j]);
			Ins(str,i+n);
		}
	}
	dfs(0);
	clear();
	for(auto i:S){
		string str="";
		if(i>0){
			for(int j=rp[i]+1;j<siz(a[i]);j++)str.pb(a[i][j]);
			Ins(str,i);
		}else{
			i=-i;
			for(int j=rq[i]+1;j<siz(qs[i]);j++)str.pb(qs[i][j]);
			Ins(str,i+n);
		}
	}
	redfs(0);
}
char readchar(){
	char ch=getchar();
	while(!isdigit(ch)&&!isalpha(ch))ch=getchar();
	return ch;
}
const ll mod1=998244853,mod2=1e9+9;
struct Hsh{
	ll a,b;	
	void pb(ll x){
		x=x-'a'+1;
		a=(a*127ll+x)%mod1;
		b=(b*127ll+x)%mod2;
	}
	ll tolong(){
		return 1ll*a*mod2+b;
	}
};
void work(){
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	int sigmaS=0,sigmaQ=0;
	for(int i=1;i<=n;i++){
		exc(a[i]==b[i]);
		sigmaS+=2*siz(a[i]);
		int l=0,r=siz(a[i])-1;
		while(a[i][l]==b[i][l])++l;
		while(a[i][r]==b[i][r])--r;
		Hsh h={0,0};
		for(int k=l;k<=r;k++){
			h.pb(a[i][k]),h.pb(b[i][k]);
		}
		vc[h.tolong()].eb(i);
		lp[i]=l,rp[i]=r;
	}
	for(int i=1;i<=q;i++){
		string s,t;
		cin>>s>>t;
		exc(siz(s)!=siz(t));
		sigmaQ+=2*siz(s);
		qs[i]=s,qt[i]=t;
		int l=0,r=siz(s)-1;
		while(s[l]==t[l])++l;
		while(s[r]==t[r])--r;
		
		Hsh h={0,0};
		for(int k=l;k<=r;k++){
			h.pb(s[k]);
			h.pb(t[k]);
//			h=(h*127+s[k])*131+t[k];
		}
		vc[h.tolong()].eb(-i);
		lq[i]=l,rq[i]=r;
	} 
	for(auto t:vc){
		solve(t.y);
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<'\n';
	}
//	deb(sigmaS),debl(sigmaQ);
}
signed main(){
//	freopen("1.in","r",stdin);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),
	cin.tie(0),cout.tie(0);
	int T=1;while(T--)work();
}
/*
- CONTINUE, NON-STOPPING, FOR THE FAITH
- START TYPING IF YOU DON'T KNOW WHAT TO DO
- STOP TYPING IF YOU DON'T KNOW WHAT YOU'RE DOING
*/

