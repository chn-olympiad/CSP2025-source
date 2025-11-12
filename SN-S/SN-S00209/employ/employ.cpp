#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N1=103,N=503,mod=998244353;
int n,m,f[2][N][N],c[N],p[N],C[N][N],cl[N][N],cr[N][N],b[N],flag=1,fc[N],wl[N],wr[N];
void add(int &x,int y){
	x+=y;
	if(x>=mod) x-=mod;
}string str;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m>>str;
	for(int i=1;i<=n;i++){
		p[i]=str[i-1]-'0';
		cin>>c[i];
		wl[c[i]]++,wr[c[i]]++;
		flag&=p[i];
		b[i]=b[i-1]+p[i];
	}C[0][0]=fc[0]=1;
	for(int i=1;i<=n;i++){
		C[i][0]=1,fc[i]=1ll*fc[i-1]*i%mod;
		for(int j=1;j<=i;j++){
			C[i][j]=C[i-1][j];
			add(C[i][j],C[i-1][j-1]);
		}
	}
	if(flag){
		cout<<fc[n];
		return 0;
	}if(m==n){
		cout<<0;
		return 0;
	}for(int i=1;i<=n;i++) wl[i]+=wl[i-1];
	for(int i=n;i>0;i--) wr[i]+=wr[i+1];
	for(int i=1;i<=n;i++) f[1][0][i]=1;
	for(int i=0;i<n;i++){
		memcpy(f[0],f[1],sizeof(f[1]));
		memset(f[1],0,sizeof(f[1]));
		for(int j=i-b[i],t;j<=i;j++){
			t=b[i]-(i-j);
			for(int k=0;k<=n-i;k++){
				if(p[i+1]==0) add(f[1][j+1][k],f[0][j][k]);
				else{
					add(f[1][j][k-1],1ll*f[0][j][k]*max(0,wr[j+1]-k-1)%mod);
					add(f[1][j][k],1ll*f[0][j][k]*max(0,wl[j]-t));
				}
			}
			
		}
	}ll ans=0;
	for(int i=n-m;i>=0;i--) ans=(ans+f[1][i][0])%mod;
	cout<<ans*fc[n-b[n]]%mod;
	return 0;
}/*

3 2
101
1 1 2

*/