#include <bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
#define FOR(i,l,r) for(int i=(l);i<=(r);++i)
#define ROF(i,r,l) for(int i=(r);i>=(l);--i)
#define eb emplace_back
#define fr first
#define se second
using namespace std;
bool __ST;
void Document() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
}
int read() {
	int s=0,t=1;char ch=getchar();
	while(!isdigit(ch)) {if(ch=='-') t=-1;ch=getchar();}
	while(isdigit(ch)) {s=(s<<3)+(s<<1)+(ch^48);ch=getchar();}
	return s*t;
}
void Tell() {
	/*
	
	*/
}
const int N=2e5+10,L=5e6+10,P=13331,Mo=1e6+13;
int tot=0,hed[Mo+1];
//struct Edge {
//	int nxt;unsigned long long val;int cnt;
//}e[N];
//void adde(ULL x) {
//	ULL Ha=x%Mo;
//	e[++tot].nxt=hed[Ha];
//	e[tot].val=x;
//	e[tot].cnt=1;
//	hed[Ha]=tot;
//}
//void Ins(ULL x) {
//	ULL Ha=x%Mo;
//	for(int i=hed[Ha];i;i=e[i].nxt) {
//		if(e[i].val==x) {
//			++e[i].cnt;
//			return ;
//		}
//	}
//	adde(x);
//}
//int Find(ULL x) {
//	ULL Ha=x%Mo;
//	for(int i=hed[Ha];i;i=e[i].nxt) 
//		if(e[i].val==x) return e[i].cnt;
//	return 0;
//}
int n,q,f[L];
string s[N][2];
bool __ED;
int main() { 
	cerr<<(&__ED-&__ST)/1048576.<<"\n";
	Document();
	cin>>n>>q;
	FOR(i,1,n) cin>>s[i][0]>>s[i][1],s[i][0]=" "+s[i][0],s[i][1]=" "+s[i][1];
	while(q--) {
		string a,b;cin>>a>>b;a=" "+a,b=" "+b;
		if(a.size()!=b.size()) {
			puts("0");
			continue;
		}
		int ls=a.size()-1,ans=0;
		FOR(i,1,ls) f[i]=f[i-1]+(a[i]==b[i]);
		FOR(i,1,n) {
			int lc=s[i][0].size()-1,res=0;
			FOR(r,lc,(int)a.size()-1) {
				int l=r-lc+1;int ck=1;
				FOR(p,l,r) if(a[p]!=s[i][0][p-l+1]) ck=0;
				FOR(p,l,r) if(b[p]!=s[i][1][p-l+1]) ck=0;
				if(f[l-1]==l-1&&f[ls]-f[r]==ls-r) ;else ck=0;
				res+=ck;
			}
			ans+=res;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
