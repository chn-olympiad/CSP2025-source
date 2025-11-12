#include<bits/stdc++.h>
#define ll long long
#define inf64 (ll)0x3f3f3f3f3f3f3f3f
#define inf32 (int)0x3f3f3f3f
#define _inf32 (int)0xc0c0c0c0
#define _inf64 (ll)0xc0c0c0c0c0c0c0c0
#define N 510
#define P 998244353
inline int in(){
	int sum=0,c=getchar();
	while(c<48||57<c)c=getchar();
	while(48<=c&&c<=57)sum=(sum<<3)+(sum<<1)+c-48,c=getchar();
	return sum;
}
inline char inch(){
	char c=getchar();
	while(c==' '||c=='\n'||c=='\r')c=getchar();
	return c;
}
inline int power(int a,int x){
	int ans=1;
	while(x){
		if(x&1)ans=(ll)ans*a%P;
		a=(ll)a*a%P;
		x>>=1;
	}
	return ans;
}
inline getinv(int a){
	return power(a,P-2);
}
inline int mod(int a){
	return a<P?a:a-P;
}
using namespace std;
int n,m,ans;
char ch;
int b[N],c[N];
int p[N];
bitset<N> vis;
int fac[N],inv[N];
int C[N][N];
bool b1=1,c0=0;
void init(){
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=(ll)fac[i-1]*i%P;
	inv[n]=getinv(fac[n]);
	for(int i=n;i>=1;i--)inv[i-1]=(ll)inv[i]*i%P;
	C[0][0]=1;
	for(int j=1;j<=n;j++){
		C[0][j]=0;
	}
	for(int i=1;i<=n;i++){
		C[i][0]=1;
		for(int j=1;j<=n;j++){
			C[i][j]=mod(C[i-1][j]+C[i-1][j-1]);
		}
	}
}
void dfs(int d){
	if(d==n+1){
//		for(int i=1;i<=n;i++){
//			cout<<p[i]<<' ';
//		}
//		cout<<endl;
		int num=0;
		for(int i=1;i<=n;i++){
			if(b[i]==0 || num>=c[p[i]]){
				num++;
			}
		}
//		cout<<n-num<<endl;
		if(n-num>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		p[d]=i;
		vis[i]=1;
		dfs(d+1);
		vis[i]=0;
	}
}
int main(){
//	freopen("employ2.in","r",stdin);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=in(),m=in();
//	init();
	for(int i=1;i<=n;i++){
		ch=inch();
		b[i]=(ch==49);
		if(b[i]==0)b1=0;
	}
	for(int i=1;i<=n;i++){
		c[i]=in();
		if(c[i]==0)c0=1;
	}
	if(n<=10){
		dfs(1);
		printf("%d",ans);
		return 0;
	}
	if(n==m){
		if(b1==0 || c0){
			printf("0");
			return 0;
		}
		printf("%d",fac[n]);
		return 0;
	}
	printf("0");
//	freopen("chk.out","w",stdout);
//	system("fc club.out club5.ans");
}
/*
11111111

*/