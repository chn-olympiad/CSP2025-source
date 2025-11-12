#include<bits/stdc++.h>
#define ULL unsigned long long 
#define LL long long 
using namespace std;
const int N=2e5+5,M=5e6+5,p=14843,mod=998244761;
inline int read(){
	int s=0,w=1;
	char c=getchar();
	for(;c<'0'||c>'9';w*=(c=='-')?(-1):1,c=getchar());
	for(;c>='0'&&c<='9';s=s*10+c-'0',c=getchar());
	return s*w;
}
int n,q;
string s,t;
char beg[M],ed[M];
ULL s1[M],s2[M],mi[M];
map<pair<ULL,ULL> , int> mp;
ULL Hash(string &s,int len){
	ULL H=0;
	for(int i=0;i<len;i++) H=H*p+s[i];
	return H;
}
void init(ULL *s,char *c,int siz){
	for(int i=1;i<=siz;i++) s[i]=s[i-1]*p+c[i];
}
ULL get(ULL *s,int l,int r){
	return s[r]-s[l-1]*mi[r-l+1];
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	mi[0]=1;
	for(int i=1;i<M;i++) mi[i]=mi[i-1]*p;
	
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s>>t;  
		int len=s.size();
		ULL Hs=Hash(s,len),Ht=Hash(t,len);
//		cout<<Hs[i]<<' '<<Ht[i]<<'\n';
		mp[{Hs,Ht}]++;
	}  
//	puts("");
	while(q--){
		cin>>beg+1>>ed+1;
		int siz=strlen(beg+1);
		init(s1,beg,siz),init(s2,ed,siz);
		int L=0,R=siz+1;
		for(int i=1;i<=siz;i++){
			if(beg[i]==ed[i]) L=i;
			else break;
		}
		for(int i=siz;i>=1;i--){
			if(beg[i]==ed[i]) R=i;
			else break;
		}
		LL ans=0;
		for(int l=1;l<=L+1;l++){
			for(int r=R-1;r<=siz;r++){
				if(l>r) continue;
				ans+=mp[make_pair(get(s1,l,r),get(s2,l,r))];
//				cout<<l<<' '<<r<<':'<<get(s1,l,r)<<' '<<get(s2,l,r)<<'\n';
			}
		}
		printf("%lld\n",ans);
	}
 	return 0;
}

