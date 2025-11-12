//丁一宸 SN-S00001 西安高新第一中学
#include <bits/stdc++.h>
using namespace std;
#define il inline
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
	il void read(int &x,auto &...y){read(x),read(y...);}
	il void write(int x){
		short top=0,stk[10];
		do stk[top++]=x%10,x/=10;while(x);
		while(top)pc(stk[--top]|48);
		pc('\n');
	}
}
using namespace FastIO;

const int N=1e5+5;

int T,n,m,sum,tmp,top,op[N],a[N],c[3],stk[N];
il void Run(){
	read(n),m=n>>1,sum=top=c[0]=c[1]=c[2]=0,tmp=-1;
	for(int i=1,A,B,C;i<=n;i++){
		read(A,B,C);
		if(A>=B&&A>=C)op[i]=0,a[i]=A-max(B,C);
		if(B>=A&&B>=C)op[i]=1,a[i]=B-max(A,C);
		if(C>=A&&C>=B)op[i]=2,a[i]=C-max(A,B);
		c[op[i]]++,sum+=max(max(A,B),C);
	}
	if(c[0]>m)tmp=0;
	if(c[1]>m)tmp=1;
	if(c[2]>m)tmp=2;
	if(tmp!=-1){
		for(int i=1;i<=n;i++)if(op[i]==tmp)stk[++top]=a[i];
		sort(stk+1,stk+1+top);
		for(int i=1;c[tmp]>m;i++)c[tmp]--,sum-=stk[i];
	}
	write(sum);
}
il void main(){
	for(read(T);T;T--)Run();
	flush();
}}
int main(){
	freopen("club.in","r",stdin),freopen("club.out","w",stdout);
	DYC::main();
}
