#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int maxn=2e3+10;
const int base=131;
int read() {
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)) {
		if(c=='-') f=-1;
		c=getchar();
	} while(isdigit(c)) {
		x=(x<<1)+(x<<3)+(c-'0');
		c=getchar();
	} return x*f;
}

int n,q,m,ans=0;
char s[maxn][2][maxn],t[maxn][2];
int ha[maxn][2],hh[maxn][2],len[maxn];

int qpow(int x,int a) {
	int res=1;
	while(a) {
		if(a&1) res*=x;
		x*=x,a>>=1;
	} return res;
}
void hax(int opt) {
	for(int i=1;i<=m;i++) {
		hh[i][opt]=base*hh[i-1][opt]+(t[opt][i]-'a'+1);
	}
}

int get(int l,int r,int opt) {
	if(l>r) return 0;
	return hh[r][opt]-hh[l][opt]*qpow(base,r-l);
}
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++) {
		cin>>(s[i][0]+1)>>(s[i][1]+1);
	}
	for(int i=1;i<=n;i++) {
		len[i]=strlen(s[i][0]+1);
//		cout<<"len."<<len[i]<<"\n";
		for(int j=0;j<=1;j++) {
			int res=0;
			for(int k=1;k<=len[i];k++) {
				res=res*base+(s[i][j][k]-'a'+1);
			} ha[i][j]=res;
		}
	}
	while(q--) {
		ans=0;
		cin>>(t[0]+1)>>(t[1]+1); m=strlen(t[0]+1);
		for(int i=0;i<=1;i++) hax(i);
		for(int i=1;i<=m;i++) {
			for(int j=1;j<=n;j++) {
				if(m-i+1<len[j]) break;
				if(get(i,i+len[j]-1,0)!=ha[j][0]) continue;
				
				int val=hh[i-1][0]*qpow(base,m-i)+ha[j][0]*qpow(base,m-(i+len[j]-1))+get(i+len[j],m,0);
				
				if(val==hh[m][1]) {
					ans++;
				}
			}
		} cout<<ans<<"\n";
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/