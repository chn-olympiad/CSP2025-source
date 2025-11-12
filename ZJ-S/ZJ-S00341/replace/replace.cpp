#include<bits/stdc++.h>
#define int long long
#define debug printf("!!!\n")
using namespace std;
int read(){
	char c=getchar();
	int x=0,f=1;
	for(;c<'0'||c>'9';c=getchar()){
		if(c=='-') f=-1;
	}
	for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
	return x*f;
}
void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
void write(int x,char c){
	write(x);putchar(c);
}
const int N=2e5+5,M=5e6+5,base=137,mod=993244853;
int n,q,pw[M],h1[M],h2[M],inv[M];
struct node{
	vector<int> v1,v2;
	int len;
	void calc(char *s1,char *s2,int len){
		for(int i=1;i<=len;i++) v1[i]=(v1[i-1]*base%mod+s1[i]-'a'+1)%mod;
		for(int i=1;i<=len;i++) v2[i]=(v2[i-1]*base%mod+s2[i]-'a'+1)%mod;
	}
}a[N];
char s1[M],s2[M];
int qp(int x,int y){
	int res=1;
	for(;y;y>>=1,x=x*x%mod) if(y&1) res=res*x%mod;
	return res;
}
void init(int n){
	for(int i=pw[0]=1;i<=n;i++) pw[i]=pw[i-1]*base%mod;
	int t=qp(base,mod-2);
	for(int i=inv[0]=1;i<=n;i++) inv[i]=inv[i-1]*t%mod;
}
bool cmp(int *a,int l1,int r1,vector<int> b,int l2,int r2){
	int h1=(a[r1]-a[l1-1]*pw[r1-l1+1]%mod+mod)%mod,h2=(b[r2]-b[l2-1]*pw[r2-l2+1]%mod+mod)%mod;
	return h1==h2;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	init(M-5);
	n=read();q=read();
	for(int i=1;i<=n;i++){
		scanf("%s%s",s1+1,s2+1);
		a[i].len=strlen(s1+1);
		a[i].v1.resize(a[i].len+2);
		a[i].v2.resize(a[i].len+2);
		a[i].calc(s1,s2,a[i].len);
	}
	for(;q--;){
		scanf("%s%s",s1+1,s2+1);
		int len=strlen(s1+1),_=strlen(s2+1);
		if(len!=_){
			printf("0\n");
			continue;
		}
		for(int i=1;i<=len;i++) h1[i]=(h1[i-1]*base%mod+s1[i]-'a'+1)%mod;
		for(int i=1;i<=len;i++) h2[i]=(h2[i-1]*base%mod+s2[i]-'a'+1)%mod;
		int p1=1,p2=len,ans=0;
		for(;p1<=len&&s1[p1]==s2[p1];p1++);
		p1--;
		for(;p2&&s1[p2]==s2[p2];p2--);
		p2++;
		for(int i=1;i<=n;i++){
			int l=a[i].len;
			for(int j=1;j+l-1<=len;j++){
				if(j-1<=p1&&j+l>=p2){
					if(cmp(h1,j,j+l-1,a[i].v1,1,l)&&cmp(h2,j,j+l-1,a[i].v2,1,l)) ans++;
				}
			}
		}
		write(ans,'\n');
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
*/
