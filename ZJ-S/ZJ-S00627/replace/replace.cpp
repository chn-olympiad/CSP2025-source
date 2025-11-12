#include <bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
const int maxn=2e5+5,maxm=5e6+5,base=37;
int n,q;
multiset<pair<ull,ull> > st;
ull pw[maxm],HS[maxm],HT[maxm];
inline int read(){
	int ret=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-f;c=getchar();}
	while(isdigit(c)){ret=ret*10+c-'0';c=getchar();}
	return ret*f;
}
inline string sred(){
	string s;char c=getchar();
	while(c<'a'||c>'z')c=getchar();
	while('a'<=c&&c<='z')s.push_back(c),c=getchar();
	return s;
}
inline ull GetS(int l,int r){
	return HS[r]-HS[l-1]*pw[r-l+1];
}
inline ull GetT(int l,int r){
	return HT[r]-HT[l-1]*pw[r-l+1];
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++){
		string s=" "+sred();int len=s.size()-1;ull H1=0,H2=0;
		for(int j=1;j<=len;j++)H1=H1*base+s[j]-'a'+1;
		s=" "+sred();
		for(int j=1;j<=len;j++)H2=H2*base+s[j]-'a'+1;
		st.insert({H1,H2});
	}
	pw[0]=1;
	while(q--){
		string S=" "+sred(),T=" "+sred();
		int len1=S.size()-1,len2=T.size()-1;
		if(len1!=len2){putchar('0'),putchar('\n');continue;}
		int N=len1;
		for(int i=1;i<=N;i++)HS[i]=HS[i-1]*base+S[i]-'a'+1,pw[i]=pw[i-1]*base;
		for(int i=1;i<=N;i++)HT[i]=HT[i-1]*base+T[i]-'a'+1;
		int L=0,R=N+1;
		for(int i=1;i<=N;i++)
			if(S[i]!=T[i]){L=i;break;}
		for(int i=N;i>=1;i--)
			if(S[i]!=T[i]){R=i;break;}
		int ans=0;
		for(int l=1;l<=L;l++)
			for(int r=R;r<=N;r++)ans+=st.count({GetS(l,r),GetT(l,r)});
		printf("%d\n",ans);
	}
	return 0;
}