//Li Ruisi SN-S00368 Xi'an Tieyi High School
#include<bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define mod (998244353)
#define int long long
using namespace std;
inline int read(){
	int n=0,s=1;
	char x=0;
	while((x=getchar())<'0'||x>'9')
		if(x=='-')
			s=-1;
	while(x>='0'&&x<='9'){
		n=(n*10)+(x^48);
		x=getchar();
	}
	return n*s;
}
void write(int n,char x=0){
	if(n<0){
		putchar('-');
		n=-n;
	}
	if(n>=10)write(n/10);
	putchar('0'+n%10);
	if(x)putchar(x);
}
int pw(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
int jc[1001],inv[1001];
int C(int i,int j){
	if(j<0||j>i)return 0;
	return jc[i]*inv[j]%mod*inv[i-j]%mod;
}
int A(int i,int j){
	return C(i,j)*jc[j]%mod;
}
char s[505];
int cnt[501];
int suf[502];
int f[2][501][501];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	jc[0]=inv[0]=1;
	for(int i=1;i<=1000;i++)jc[i]=jc[i-1]*i%mod,inv[i]=pw(jc[i],mod-2);
	int n=read(),m=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)cnt[read()]++;
	for(int i=n;i>=1;i--)suf[i]=suf[i+1]+cnt[i];
	for(int i=m;i<=n;i++)f[n&1][i][0]=1;
	int cc=0;
	int tim=0;
	for(int i=n;i>=1;i--){
		int now=i&1,nxt=!now;
		memset(f[nxt],0,sizeof(f[nxt]));
		for(int j=0;j<=i;j++)for(int k=0;k<=cc;k++)if(f[now][j][k]){//
//			cout<<f[now][j][k]<<" \n"[k==n];
			if(s[i]=='1'&&j){
				int las=suf[i-j+1]-(cc-k);
				f[nxt][j-1][k]=(f[nxt][j-1][k]+f[now][j][k]*las)%mod;
			}
			int o=(s[i]=='1');
			for(int kp=max(0ll,k-cnt[i-j]);kp<=k;kp++){
				tim++;
				f[nxt][j][kp+o]=(f[nxt][j][kp+o]+f[now][j][k]*C(k,k-kp)%mod*A(cnt[i-j],k-kp))%mod;
//				f[nxt][j][kp+o]=(f[nxt][j][kp+o]+f[now][j][k]*C(cnt[i-j],k-kp)%mod*(o?kp+1:1))%mod;
			}
		}
//		cout<<"\n";
		cc+=(s[i]=='1');
	}
//	cout<<tim<<"\n";
	int ans=0;
	for(int k=0;k<=cnt[0];k++)ans=(ans+f[0][0][k]*A(cnt[0],k)%mod*jc[n-cc])%mod;
	write(ans);
	return 0;
}
/*
3 1
101
0 1 2
*/
