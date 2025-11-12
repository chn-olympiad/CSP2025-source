//丁一宸 SN-S00001 西安高新第一中学
#include <bits/stdc++.h>
using namespace std;
#define il inline
#define ps push_back
#define ll long long
#define lw lower_bound 
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
		while(ch<'a'||ch>'z')ch=gc();
		while(ch>='a'&&ch<='z')x+=ch,ch=gc(); 
	}
	il void read(auto &x,auto &...y){read(x),read(y...);}
	il void write(int x){
		short top=0,stk[10];
		do stk[top++]=x%10,x/=10;while(x);
		while(top)pc(stk[--top]|48);
		pc('\n');
	}
}
using namespace FastIO;

const int N=2e5+5,L=5e6+5,M=3200,Q=233,P=998244353;

int n,m,q,bas[L],hsh[N][2],len[N],tmp[N],_hsh[2][L];
unordered_map<ll,int>chk[M];
string s[2],t[2];
il void main(){
	read(n,q),bas[0]=1;
	for(int i=1;i<=5e6;i++)bas[i]=1ll*bas[i-1]*Q%P;
	for(int i=1;i<=n;i++){
		read(s[0],s[1]),tmp[i]=len[i]=s[0].length();
		for(int o:{0,1})for(int p=0;p<len[i];p++)
			hsh[i][o]=(1ll*hsh[i][o]*Q+s[o][p])%P;
	}
	sort(len+1,len+1+n),m=unique(len+1,len+1+n)-len-1;
	for(int i=1;i<=n;i++)chk[lw(len+1,len+1+m,tmp[i])-len][1ll*hsh[i][0]*P+hsh[i][1]]++;
	for(int i=1,cnt;i<=q;i++){
		read(t[0],t[1]),cnt=0;
		if(t[0].length()!=t[1].length()){write(0);continue;}
		int Len=t[0].length(),L=0,R=Len;
		for(int o:{0,1})for(int p=0;p<Len;p++)
			_hsh[o][p+1]=(1ll*_hsh[o][p]*Q+t[o][p])%P; 
		while(t[0][L]==t[1][L])L++;
		while(t[0][R-1]==t[1][R-1])R--;
		for(int p=R;p<=Len;p++)for(int t=1;t<=m&&len[t]<=p;t++){
			if(p-L>len[t])continue;
			int hsh0=(_hsh[0][p]-1ll*_hsh[0][p-len[t]]*bas[len[t]]%P+P)%P;
			int hsh1=(_hsh[1][p]-1ll*_hsh[1][p-len[t]]*bas[len[t]]%P+P)%P;
			cnt+=chk[t][1ll*hsh0*P+hsh1];
		}
		write(cnt);
	}
	flush();
}}
int main(){
	freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
	DYC::main();
}
