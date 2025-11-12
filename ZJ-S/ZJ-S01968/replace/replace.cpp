#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
using namespace std;
const int N=2e5+5,M=5e6+5,mod=1e9+9,B=31;
int n,m,cnt,dd[30],lh[M],rh[M];
char s[M],t[M];
unordered_map<int,int> f;
unordered_map<int,unordered_map<int,int> > g[N];
set<int> L[N],R[N];
mt19937 rnd(time(0));
inline int add(int v,char c){assert(c>='a'&&c<='z');return (1ll*v*B+dd[c^96])%mod;}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	iota(dd+1,dd+27,1),shuffle(dd+1,dd+27,rnd);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>(s+1)>>(t+1);
		int ln=strlen(s+1),l=1,r=ln;
		while(l<=ln&&s[l]==t[l])l++;
		while(r>=1&&s[r]==t[r])r--;
		if(l>n)continue;
		int v=0;
		for(int j=l;j<=r;j++)v=add(v,s[j]),v=add(v,t[j]);
		int p=f.count(v)?f[v]:f[v]=++cnt;
		L[p].insert(l-1),R[p].insert(ln-r);
		int lv=0,rv=0;
		for(int j=l-1;j;j--)lv=add(lv,s[j]);
		for(int j=r+1;j<=ln;j++)rv=add(rv,s[j]);
		g[p][lv][rv]++;
	}
	for(int i=1;i<=m;i++){
		cin>>(s+1)>>(t+1);
		int ln=strlen(s+1),l=1,r=ln,v=0;
		if(ln!=(int)strlen(t+1)){cout<<"0\n";continue;}
		while(s[l]==t[l])l++;
		while(s[r]==t[r])r--;
		for(int j=l;j<=r;j++)v=add(v,s[j]),v=add(v,t[j]);
		if(!f.count(v)){cout<<"0\n";continue;}
		int p=f[v],ans=0;
		for(int j=1;j<l;j++)lh[j]=add(lh[j-1],s[l-j]);
		for(int j=1;j<=ln-r;j++)rh[j]=add(rh[j-1],s[r+j]);
		for(int j:L[p]){
			if(j>l-1)break;
			if(!g[p].count(lh[j]))continue;
			auto &S=g[p][lh[j]];
			for(int k:R[p]){
				if(k>ln-r)break;
				if(S.count(rh[k]))ans+=S[rh[k]];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}