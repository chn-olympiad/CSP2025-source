#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=5e6+10;
const ull base=1031;
int n,q,ll[N];
ull bas[N],hsh1[N],hsh2[N],hsh[N][3];
string s[N][3],t1,t2;
ull gethsh1(int L,int R) {
	return hsh1[R]-hsh1[L-1]*bas[R-L+1];
}
ull gethsh2(int L,int R) {
	return hsh2[R]-hsh2[L-1]*bas[R-L+1];
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1; i<=n; ++i) {
		cin>>s[i][1]>>s[i][2];
		ll[i]=s[i][1].size();
		s[i][1]=' '+s[i][1],s[i][2]=' '+s[i][2];
		for(int j=1; j<=2; ++j) {
			for(int w=1; w<=ll[i]; ++w) {
				hsh[i][j]=hsh[i][j]*base+s[i][j][w];
			}
		}
	}
	bas[0]=1;
	for(int i=1; i<=5000000; ++i)bas[i]=bas[i-1]*base;
	for(int j=1; j<=q; ++j) {
		cin>>t1>>t2;
		int len1=t1.size(),len2=t2.size();
		t1=' '+t1,t2=' '+t2;
		if(len1!=len2) {
			puts("0");
			continue;
		}
		for(int i=1; i<=len1; ++i) {
			hsh1[i]=hsh1[i-1]*base+t1[i];
		}
		for(int i=1; i<=len2; ++i) {
			hsh2[i]=hsh2[i-1]*base+t2[i];
		}
		int pre=0,suf=len1;
		for(; pre<len1; ++pre) {
			if(t1[pre]!=t2[pre]) {
				break;
			}
		}
		for(; suf>=0; --suf) {
			if(t1[suf]!=t2[suf]) {
				break;
			}
		}
		int res=0;
		for(int w=1; w<=n; ++w) {
			int f=0;
			if(ll[w]>len1)continue;
			for(int L=max(1,suf-ll[w]+1); L<=pre; ++L) {
				int R=L+ll[w]-1;
				if(gethsh1(L,R)==hsh[w][1]&&gethsh2(L,R)==hsh[w][2]) {
					f=1;
					break;
				}
			}
			res+=f;
		}
		printf("%d\n",res);
	}
}

