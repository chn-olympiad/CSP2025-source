//丁一宸 SN-S00001 西安高新第一中学
#include <bits/stdc++.h>
using namespace std;
#define il inline
#define ps push_back
#define bpc __builtin_popcount
#define Fail write(0),flush(),void() 
namespace DYC{
namespace FastIO{
	const int LEN=1<<20;
	char buf[LEN],obuf[LEN],*p1=buf,*p2=buf,*p3=obuf;
	il char gc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,LEN,stdin),p1==p2)?EOF:*p1++;}
	il void flush(){fwrite(obuf,1,p3-obuf,stdout),p3=obuf;}
	il void pc(char x){p3-obuf==LEN?flush():void(),*p3++=x;}
	il void read(int &x){
		char ch=gc();x=0;
		while(ch<'0'||ch>'9')ch=gc();
		while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=gc();
	}
	il void read(string &x){
		char ch=gc();x="";
		while(ch!='0'&&ch!='1')ch=gc();
		while(ch=='0'||ch=='1')x+=ch,ch=gc(); 
	}
	il void read(auto &x,auto &...y){read(x),read(y...);}
	il void write(int x){
		short top=0,stk[10];
		do stk[top++]=x%10,x/=10;while(x);
		while(top)pc(stk[--top]|48);
	}
}
using namespace FastIO;

const int N=505,K=20,H=262144,P=998244353;

int n,m,h,ans,c[N],dp[H][K];
string s;
vector<int>opt[K];
il void Dadd(int &a,int b){(a+=b)>=P?a-=P:0;}
il void main(){
	read(n,m,s);
	for(int i=0;i<n;i++)read(c[i]);
	if(n<=18){
		h=1<<n,dp[0][0]=1;
		for(int S=0;S<h;S++)opt[bpc(S)].ps(S);
		for(int i=0;i<n;i++)for(int S:opt[i])
			for(int c0=0,c1=i;c1>=0;c0++,c1--)if(dp[S][c1])
				for(int p=0;p<n;p++)if(~S>>p&1)
					Dadd(dp[S|1<<p][c1+(s[i]=='1'&&c0<c[p])],dp[S][c1]);
		for(int c=m;c<=n;c++)Dadd(ans,dp[h-1][c]);
	}else if(m==n){
		for(int i=0;i<n;i++)if(s[i]=='0'||!c[i])return Fail;
		ans=1;
		for(int i=1;i<=n;i++)ans=1ll*ans*i%P;
	}
	write(ans),flush();
}}
int main(){
	freopen("employ.in","r",stdin),freopen("employ.out","w",stdout);
	DYC::main();
}
