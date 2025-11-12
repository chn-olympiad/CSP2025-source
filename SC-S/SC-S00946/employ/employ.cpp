#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const int mod=998244353;
long long qw(long long x,long long y){
	long long res=1;
	while(y){
		if(y&1) res=(res*x)%mod;
		y>>=1;
		x=(x*x)%mod;
	}
	return res;
}//快速幂


int fac[1000100],inv[1000100];
void pre(){
	fac[0]=1;
	for(int i=1;i<=1000000;i++){
		fac[i]=((long long)fac[i-1]*i)%mod;
	}
	inv[1000000]=qw(fac[1000000],mod-2);
	for(int i=1000000-1;i>=0;i--){
		inv[i]=((long long)inv[i+1]*(i+1))%mod;
	}
}
//int cl(int x,int y){
//	if(y>x) return 0;
//	return ((long long)fac[x]*inv[x-y]*inv[y])%mod;
//}//组合数

int n,m;
char a[600];
int c[600];
int li[60];
bool p=1;
//int dp[510][510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	pre();
	scanf("%s",a+1);
	for(int i=1;i<=(int)strlen(a+1);i++){
		if(a[i]!='1') p=0;
	}
	for(int i=1;i<=n;i++)c[i]=read();
	sort(c+1,c+n+1);
	if(n<=18){
		int cnt=fac[n],ans=0,ccc=0;
		for(int i=1;i<=n;i++) li[i]=i;	
		while(cnt--){
//			for(int i=1;i<=n;i++) cout<<li[i]<<" ";
//			cout<<endl;
//			for(int i=1;i<=n;i++) cout<<c[li[i]]<<" ";
//			cout<<endl<<endl;
			ccc=0;
			for(int i=1;i<=n;i++){
				if(ccc>=c[li[i]]) ccc++;
				else if(a[i]=='0') ccc++;
			}
			if(n-ccc>=m) ans++;
			next_permutation(li+1,li+n+1);			
		}
		cout<<ans;
//		for(int i=1;i<=n;i++) cout<<li[i]<<" ";
	}
	else if(m==n){
		if(!p){
			cout<<0;
			return 0;
		}
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				cout<<0;
				return 0;
			}
		}
		cout<<fac[n];
	}	
	else cout<<0;
//	else if(m==1){
//		long long zong=fac[n];
//		long long qu=0;
//		int dp[510][510]={0};
//		for(int i=1;i<=n;i++){
//			
//		}
//	}
//	else if(p){
//		
//	}

	return 0;
}