#include<bits/stdc++.h>
#define mkp(a,b) make_pair(a,b)
#define fst first
#define sec second
using namespace std;
typedef long long LL;
typedef pair<LL,LL> pii;
const int B1=133,mod1=998244353;
const int B2=233,mod2=1e9+7;
const int maxn=1e4+5;
const int maxm=1e6+5;
void read(int& x){
	char c;
	bool f=0;
	while((c=getchar())<48) f|=(c==45);
	x=c-48;
	while((c=getchar())>47) x=x*10+c-48;
	x=(f ? -x : x);
}
int n,m;
string s1[maxn],s2[maxn];
pii hs1[maxn],hs2[maxn];
LL fpow(LL x,int y,int mod){
	LL ans=1;
	while(y){
		if(y&1) ans=ans*x%mod;
		x=x*x%mod,y>>=1;
	}
	return ans;
}
pii h1[maxm],h2[maxm];
pii cal(int l,int r,pii* a){
	if(l==0) return a[r];
	return mkp((a[r].fst+mod1-a[l-1].fst*fpow(B1,r-l+1,mod1)%mod1)%mod1,\
	(a[r].sec+mod2-a[l-1].sec*fpow(B2,r-l+1,mod2)%mod2)%mod2);
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		hs1[i]=mkp(0,0);
		for(int j=0;j<(int)s1[i].size();j++){
			hs1[i]=mkp((hs1[i].fst*B1+s1[i][j])%mod1,(hs1[i].sec*B2+s1[i][j])%mod2);
		}
		hs2[i]=mkp(0,0);
		for(int j=0;j<(int)s2[i].size();j++){
			hs2[i]=mkp((hs2[i].fst*B1+s2[i][j])%mod1,(hs2[i].sec*B2+s2[i][j])%mod2);
		}
	}
	string a,b;
	while(m--){
		cin>>a>>b;
		h1[0]=mkp(a[0],a[0]);
		for(int j=1;j<(int)a.size();j++){
			h1[j]=mkp((h1[j-1].fst*B1+a[j])%mod1,(h1[j-1].sec*B2+a[j])%mod2);
		}
		h2[0]=mkp(b[0],b[0]);
		for(int j=1;j<(int)b.size();j++){
			h2[j]=mkp((h2[j-1].fst*B1+b[j])%mod1,(h2[j-1].sec*B2+b[j])%mod2);
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			int ppp=s1[i].size(),qqq=s2[i].size();
			for(int j=0;j<min((int)a.size()-(int)s1[i].size(),(int)b.size()-(int)s2[i].size())+1;j++){
				if(cal(j,j+ppp-1,h1)==hs1[i]&&cal(j,j+qqq-1,h2)==hs2[i]){
					if(cal(0,j-1,h1)==cal(0,j-1,h2)&&cal(j+ppp,(int)a.size()-1,h1)==cal(j+qqq,(int)b.size()-1,h2)){
						++ans;
					}
				}
			}
		}
		printf("%d\n",ans);
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
0
*/
