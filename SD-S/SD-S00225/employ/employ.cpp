#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define int long long 
inline int Read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+c-48;c=getchar();}
	return x*f;
}
inline void Write(int x){
	if(x<0){x=-x;putchar('-');}
	if(x>9) Write(x/10);
	putchar(x%10+'0');
}
const int N=510;
const int mod=998244353;
int n,m,c[N],a[N],ans=0;
int jc[N];
char s[N];
int qsm(int a,int b){
	int res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res%mod;
}
int C(int n,int m){
	return jc[n]%mod*qsm(jc[m],mod-2)%mod*qsm(jc[n-m],mod-2)%mod;
}
int A(int n,int m){
	return jc[n]%mod*qsm(jc[m-1],mod-2)%mod;
}
bool tp_A(){
	for(int i=1;i<=n;i++) if(a[i]==0) return 0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(c[i]==0) cnt++;
	}
	if(n-m<cnt) {
		printf("0\n");
		return 1;
	}
	ans=jc[n-m]%mod*A(n-cnt,m)%mod;
	ans%=mod;
	
	printf("%lld\n",ans);
	return 1;
}
bool tp1(){
	if(m!=1) return 0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(c[i]==0) cnt++;
	}
//	ans=jc[n-1]%mod*(n-cnt)%mod;
	ans=jc[n];
	printf("%lld\n",ans);
	return 1;
}
bool tpm(){
	if(m!=n) return 0;
	bool fl=1;
	for(int i=1;i<=n;i++){
		if(a[i]==0) fl=0;
		if(c[i]==0) fl=0;
	}
	if(!fl) printf("0");
	else printf("%lld\n",jc[n]);
	return 1;
}
bool vis[N];
void dfs(int t,int cnt){
	if(t==n){
		if(cnt>=m){
			ans++;
			ans%=mod;			
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		if(t-cnt>=c[i]) {
			dfs(t+1,cnt);
		}
		else {
			if(a[t+1]==0) {
				dfs(t+1,cnt);
			}
			else dfs(t+1,cnt+1);
		}
		vis[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=Read();m=Read();
	scanf("%s",s);
	for(int i=0;i<n;i++) a[i+1]=s[i]-'0';
	for(int i=1;i<=n;i++) c[i]=Read();
	jc[0]=1;
	for(int i=1;i<N-5;i++) jc[i]=jc[i-1]*i%mod;
	if(tpm()) return 0;
	if(tp_A()) return 0;
	if(tp1()) return 0;
//	if(n<=11){
		dfs(0,0);
		printf("%lld\n",ans);	
//		return 0;	
//	}
	
	return 0 ;
}

