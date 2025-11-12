#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define pii pair<int,int>
#define fr first
#define sc second
#define gtc getchar
#define ptc putchar
inline ll read(){
	ll x=0,f=1; char ch=gtc();
	while(ch<'0'||ch>'9'){ if(ch=='-') f=-1; ch=gtc(); }
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=gtc();
	return x*f;
}
inline void write(ll x){
	if(x<0) ptc('-'),x=-x;
	if(x>9) write(x/10);
	ptc(x%10+'0');
}
inline void println(ll x){ write(x),ptc('\n'); }
inline void printsp(ll x){ write(x),ptc(' '); }
const int maxl=5e6+6,maxn=2e5+5,B=211,mod=998244853;
int n,q;
string s[maxn][4]; 
int hs[maxn][4],buc1[maxl],buc2[maxl],powb[maxl];
string t[4];

int figure(string tmp){
	int len=tmp.size()-1,res=0;
	for(int i=1;i<=len;i++)
		res=(res*B%mod+tmp[i]-'a'+1)%mod;
	return res;
}

inline int query1(int l,int r){
	return (buc1[r]-buc1[l-1]*powb[r-l+1]%mod+mod)%mod;
}
inline int query2(int l,int r){
	return (buc2[r]-buc2[l-1]*powb[r-l+1]%mod+mod)%mod;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		s[i][1]=" "+s[i][1],s[i][2]=" "+s[i][2];
		hs[i][1]=figure(s[i][1]);
		hs[i][2]=figure(s[i][2]);
	}
	powb[0]=1;
	for(int i=1;i<=5e6;i++) powb[i]=powb[i-1]*B%mod;
	while(q--){
		cin>>t[1]>>t[2];
		t[1]=" "+t[1],t[2]=" "+t[2];
		int len=t[1].size()-1;
		if(len!=t[2].size()-1){
			puts("0");
			continue; 
		}
		int lcp=0,rcp=0;
		for(int i=1;i<=len;i++){
			if(t[1][i]==t[2][i]) lcp++;
			else break;
		}
		for(int i=len;i>=1;i--){
			if(t[1][i]==t[2][i]) rcp++;
			else break;
		}
		for(int i=1;i<=len;i++) 
			buc1[i]=(buc1[i-1]*B%mod+t[1][i]-'a'+1)%mod;
		for(int i=1;i<=len;i++)
			buc2[i]=(buc2[i-1]*B%mod+t[2][i]-'a'+1)%mod;
//		cout<<"wasdlfkjasd\n";
//		cout<<lcp<<" "<<rcp<<" "<<len<<" lcp rcp len\n";
		int ans=0;
		for(int i=1;i<=n;i++){
//			cout<<i<<" : \n";
			int lens=s[i][1].size()-1;
//			cout<<lens<<" lens\n";
			for(int r=1;r<=len;r++){//Ã¶¾ÙyµÄÓÒ¶Ëµã 
				int l=r-lens+1;
				if(l>lcp+1||r<len-rcp) continue;
//				if(i==3&&l==3&&r==4) cout<<"pass it\n";
				if(query1(l,r)==hs[i][1]&&query2(l,r)==hs[i][2])
					ans++/*,cout<<l<<" "<<r<<" [l,r]\n"*/;
			}
		}
		println(ans);
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

wrong sample:

5 1
xabcd agced
abcde agced
bcdef gcedf
bcd gce
bcdefax gcedfax
xabcdefax xagcedfax
*/
