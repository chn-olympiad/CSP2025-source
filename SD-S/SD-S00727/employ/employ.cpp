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
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
}
int read() {
	int s=0,t=1;char ch=getchar();
	while(!isdigit(ch)) {if(ch=='-') t=-1;ch=getchar();}
	while(isdigit(ch)) {s=(s<<3)+(s<<1)+(ch^48);ch=getchar();}
	return s*t;
}
const int N=2e5+10;
int n,m,p[N],c[N];
char s[N];
bool __ED;
int main() { cerr<<(&__ED-&__ST)/1048576.<<"\n";
	Document();
	cin>>n>>m;
	scanf("%s",s+1);
	FOR(i,1,n) c[i]=read();
	FOR(i,1,n) p[i]=i;
	int ans=0;
	do {
		int ne=0;
		FOR(i,1,n) {
			if(c[p[i]]<=ne||s[i]=='0') ++ne;
		}
		if(n-ne>=m) ++ans;
	} while(next_permutation(p+1,p+n+1));
	cout<<ans<<"\n";
	return 0;
}
