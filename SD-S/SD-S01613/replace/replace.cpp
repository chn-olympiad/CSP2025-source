#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char obuf[1000010],*p3=obuf;
#define pc(x) (p3==obuf+1000000&&fwrite(p3=obuf,1,1000000,stdout),*p3++=x)
void write(int x){
	static char stk[10];
	int top=0;
	do stk[top++]=x%10|48;while(x/=10);
	while(top)pc(stk[--top]);
}
const int p1=998244353,p2=1000000007,N=200010,L=5000010;
string s,t,s1,s2;
int hs1[L],hs2[L],pw1[L],pw2[L],w1[N],w2[N],len[N];
int get1(int l,int r){
	return((hs1[r]-(l?(ll)hs1[l-1]*pw1[r-l+1]:0))%p1+p1)%p1;
}
int get2(int l,int r){
	return((hs2[r]-(l?(ll)hs2[l-1]*pw2[r-l+1]:0))%p2+p2)%p2;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n,Q,ans,lcp,lcs;
	cin>>n>>Q;
	for(int i=pw1[0]=pw2[0]=1;i<2001;++i){
		pw1[i]=pw1[i-1]*31ll%p1;
		pw2[i]=pw2[i-1]*37ll%p2;
	}
	for(int i=1;i<=n;++i){
		cin>>s>>t;
		len[i]=s.size();
		for(int j=0;j<len[i];++j){
			w1[i]=(w1[i]*31ll+s[j]-96)%p1;
			w2[i]=(w2[i]*37ll+t[j]-96)%p2;
		}
	}
	while(Q--){
		cin>>s1>>s2;
		int lenn=s1.size();
		for(int i=0;i<lenn;++i){
			if(i){
				hs1[i]=hs1[i-1]*31ll%p1;
				hs2[i]=hs2[i-1]*37ll%p2;
			}
			hs1[i]=(hs1[i]+s1[i]-96)%p1;
			hs2[i]=(hs2[i]+s2[i]-96)%p2;
		}
		for(int i=0;i<lenn;++i){
			if(s1[i]!=s2[i]){
				lcp=i;
				break;
			}
		}
		for(int i=lenn-1;i;--i){
			if(s1[i]!=s2[i]){
				lcs=i;
				break; 
			}
		}
		ans=0;
		for(int i=lcs;i<lenn;++i){
			for(int j=1;j<=n;++j){
				if(i-len[j]>-2&&i-len[j]<lcp&&get1(i-len[j]+1,i)==w1[j]&&get2(i-len[j]+1,i)==w2[j]){
					++ans;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
//充满鲜花的世界到底在哪里 
