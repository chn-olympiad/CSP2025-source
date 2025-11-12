#include<bits/stdc++.h>
typedef long long ll;
typedef std::pair<int,int> pii;
inline void rd(){}
template<typename T,typename ...U>
inline void rd(T &x,U &...args){
	T f=1;x=0;int ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48,ch=getchar();}
	x*=f;rd(args...);
}
const int N=505,mod=998244353;
int n,m,f[N][N][N],v[N],t[N];
int g[N][N],C[N][N],b[N],d[N];
char s[N];
inline void Add(int &a,int b){(a+=b)>=mod?a-=mod:1;}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	rd(n,m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)v[i]=s[i]-'0';
	for(int i=1;i<=n;i++){
		int x;rd(x);t[x]++;
	}
	for(int i=1;i<=n;i++)t[i]+=t[i-1];
	for(int i=0;i<=n;i++){
		g[i][0]=C[i][0]=1;
		for(int j=1;j<=i;j++){
			g[i][j]=1ll*g[i][j-1]*(i-j+1)%mod;
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
	f[0][0][0]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			for(int k=0;k<=i;k++){
				
				for(int c=0;c<=t[j+1]-t[j];c++){
					b[c]=1ll*f[i][j][k]*g[t[j+1]-t[j]][c]%mod;
					d[c]=1ll*b[c]*C[i-k][c]%mod;
				}
				
				if(v[i+1]==1){
					Add(f[i+1][j][k],f[i][j][k]);
					for(int c=0;c<=t[j+1]-t[j];c++){
						Add(f[i+1][j+1][k+1+c],1ll*d[c]*(t[j]-k)%mod);
					}
				}else{
					for(int c=0;c<=t[j+1]-t[j];c++){
						Add(f[i+1][j+1][k+1+c],1ll*d[c]*(t[j]-k)%mod);
					}
					for(int c=1;c<=t[j+1]-t[j];c++){
						Add(f[i+1][j+1][k+c],1ll*b[c]*C[i-k][c-1]%mod);
					}
					for(int c=0;c<=t[j+1]-t[j];c++){
						Add(f[i+1][j+1][k+c],d[c]);
					}
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n-m;i++){
		Add(ans,1ll*f[n][i][t[i]]*g[n-t[i]][n-t[i]]%mod);
	}
	printf("%d\n",ans);
	return 0;
}
