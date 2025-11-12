#include<bits/stdc++.h>
#define ll long long
#define low(X) (X&(-X))
#define pb(A) push_back(A)
#define mk(A,B) make_pair(A,B)
using namespace std;
ll read(){
	ll S=0,F=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')F*=-1;
		ch=getchar();
	}while(isdigit(ch)){
		S=(S<<3)+(S<<1)+(ch^48);
		ch=getchar();
	}return S*F;
}const int N=500,MOD=998244353;
void upd(ll &A,ll B){
//	printf("%d %d\n",A,B);
	A=(A+B)%MOD;
}ll power(ll A,ll B){
	ll C=1;while(B){
		if(B&1)C=C*A%MOD;
		B>>=1;A=A*A%MOD;
	}return C;
}ll fac[N+10],inv[N+10];
ll C(int n,int m){
	if(n<m)return 0ll;
	return fac[n]*inv[m]%MOD*inv[n-m]%MOD;
}int n,m,s[N+10],c[N+10];
int vc[N+10],ps[N+10];
ll g[N+5][N+5],f[N+5][N+5];
int main(){
	fac[0]=inv[0]=1;
	for(int i=1;i<=N;i++)fac[i]=fac[i-1]*i%MOD;
	inv[N]=power(fac[N],MOD-2);
	for(int i=N-1;i>0;i--)inv[i]=inv[i+1]*(i+1)%MOD;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();m=read();
	string str;cin>>str;
	for(int i=1;i<=n;i++){
		s[i]=str[i-1]-'0';
	}for(int i=1;i<=n;i++){
		c[i]=read();
		vc[c[i]]++;
	}for(int i=0;i<=n;i++)ps[i]=vc[i];
	for(int i=1;i<=n;i++)ps[i]+=ps[i-1];
	f[0][vc[0]]=1;
	for(int i=0;i<n;i++){
		memcpy(g,f,sizeof(g));
		memset(f,0,sizeof(f));
		
		for(int j=0;j<=n-m;j++){
			for(int k=0;k<=ps[j];k++){
				if(!g[j][k])continue;
//				printf("%d %d %lld\n",j,k,g[j][k]);
				for(int o=0;o<=vc[j+1];o++)if(k+o>0)upd(f[j+1][k+o-1],fac[vc[j+1]]*inv[o]%MOD*C(i-(ps[j]-k),vc[j+1]-o)%MOD*k%MOD*g[j][k]);
				if(s[i+1]){
					upd(f[j][k],1ll*g[j][k]%MOD);
				}else{
					for(int o=0;o<=vc[j+1];o++){
						if(k+o>0)upd(f[j+1][k+o-1],fac[vc[j+1]]*inv[o]%MOD*C(i-(ps[j]-k),(vc[j+1]-o))%MOD*o%MOD*g[j][k]);
//						if((n-i-(k+o))>0)
						upd(f[j+1][k+o],fac[vc[j+1]]*inv[o]%MOD*C(i-(ps[j]-k),vc[j+1]-o)%MOD*g[j][k]);
					}
				} 
			}
		}
	}ll ans=0;
	for(int i=0;i<=n-m;i++){
		upd(ans,f[i][0]*fac[n-ps[i]]%MOD);
	}printf("%lld\n",ans);return 0;
}
