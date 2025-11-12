#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+6,M=5e6+6,mod1=1e9+7,mod2=1e9+9;
vector<int> a[M*2];
int n,q,ids[N][3],idt[3],fac1[M],fac2[M],mpt1[M][3],mpt2[M][3],mps1[1006][2006][3],mps2[1006][2006][3];
string s[N][3],t[3];
int qpow (int a,int b,int p) {
	int res=1;
	while (b) {
		if (b&1) res=res*a%p;
		a=a*a%p;
		b>>=1;
	}
	return res;
}
int jiequ11(int l,int r) { // mod mod1,solve t1
	if (r<l) return 0;
	return (mpt1[l][1]-mpt1[r+1][1]*fac1[r-l+1]%mod1+mod1)%mod1;
}
int jiequ12(int l,int r) { // mod mod1,solve t1
	if (r<l) return 0;
	return (mpt2[l][1]-mpt2[r+1][1]*fac2[r-l+1]%mod2+mod2)%mod2;
}
int jiequ21(int l,int r) { // mod mod1,solve t1
	if (r<l) return 0;
	return (mpt1[l][2]-mpt1[r+1][2]*fac1[r-l+1]%mod1+mod1)%mod1;
}
int jiequ22(int l,int r) { // mod mod1,solve t1
	if (r<l) return 0;
	return (mpt2[l][2]-mpt2[r+1][2]*fac2[r-l+1]%mod2+mod2)%mod2;
}
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	int len=0;
	for (int i=1;i<=n;++i) {
		cin>>s[i][1]>>s[i][2];
		len+=s[i][1].length()+s[i][2].length();
	}
	if (len>2000) {
			for (int i=1;i<=n;++i) {
				for (int k=1;k<=2;++k) {
					for (int j=0;j<s[i][k].length();++j) {
						if (s[i][k][j]=='b') {
							ids[i][k]=j;
							break;
						}
					}
				}
				a[ids[i][2]-ids[i][1]+5000000].push_back(i);
			}
			while (q--) {
				cin>>t[1]>>t[2];
				if (t[1].length()!=t[2].length()) {
					printf("0\n");
					continue;
				}
				for (int k=1;k<=2;++k) {
					for (int j=0;j<t[k].length();++j) {
						if (t[k][j]=='b') {
							idt[k]=j;
							break;
						}
					}
				}
				int d=idt[2]-idt[1],res=0;
				for (int x:a[d+5000000]) {
					if (ids[x][1]<=idt[1] && s[x][1].length()-ids[x][1]<=t[1].length()-idt[1]) {
						res++;
					}
				}
				printf("%lld\n",res);
			}
	}else {
		fac1[0]=fac2[0]=1;
		for (int i=1;i<=5000000;++i) fac1[i]=fac1[i-1]*26%mod1,fac2[i]=fac2[i-1]*26%mod2;
		for (int i=1;i<=n;++i) {
			for (int j=s[i][1].length()-1;j>=0;--j) {
				mps1[i][j][1]=(mps1[i][j+1][1]*26%mod1+(s[i][1][j]-'a'))%mod1;
				mps2[i][j][1]=(mps2[i][j+1][1]*26%mod2+(s[i][1][j]-'a'))%mod2;
				mps1[i][j][2]=(mps1[i][j+1][2]*26%mod1+(s[i][2][j]-'a'))%mod1;
				mps2[i][j][2]=(mps2[i][j+1][2]*26%mod2+(s[i][2][j]-'a'))%mod2;
			}
		}
		while (q--) {
			cin>>t[1]>>t[2];
			if (t[1].length()!=t[2].length()) {
				printf("0\n");
				continue;
			}
			mpt1[t[1].length()][1]=0;
			mpt2[t[1].length()][1]=0;
			mpt1[t[2].length()][2]=0;
			mpt2[t[2].length()][2]=0;
			for (int j=t[1].length()-1;j>=0;--j) {
				mpt1[j][1]=(mpt1[j+1][1]*26%mod1+(t[1][j]-'a'))%mod1;
				mpt2[j][1]=(mpt2[j+1][1]*26%mod2+(t[1][j]-'a'))%mod2;
				mpt1[j][2]=(mpt1[j+1][2]*26%mod1+(t[2][j]-'a'))%mod1;
				mpt2[j][2]=(mpt2[j+1][2]*26%mod2+(t[2][j]-'a'))%mod2;
			}
			int res=0;
			for (int l=0;l<t[1].length();++l) {
				for (int i=1;i<=n;++i) {
					int r=l+s[i][1].length()-1;
					if (r>=t[1].length()) continue;
					if (jiequ11(l,r)==mps1[i][0][1] && jiequ12(l,r)==mps2[i][0][1] 
					&& jiequ21(l,r)==mps1[i][0][2] && jiequ22(l,r)==mps2[i][0][2] 
					&& jiequ11(0,l-1)==jiequ21(0,l-1) && jiequ12(0,l-1)==jiequ22(0,l-1) 
					&& jiequ11(r+1,t[1].length()-1)==jiequ21(r+1,t[1].length()-1) && jiequ12(r+1,t[1].length()-1)==jiequ22(r+1,t[1].length()-1)) {
						res++;
					}
				}
			}
			printf("%lld\n",res);
		}
	}
	return 0;
}