#include<iostream>
using namespace std;
const int N=505,mod=998244353;
int f[N][N][N],fac[N],C[N][N],T[N][N],cnt[N],sc[N],a0[N],a1[N];
char s[N];
inline void add(int &x,int y){x+=y;if(x>=mod)x-=mod;}
void init()
{
	for(int i=fac[0]=1;i<N;++i)fac[i]=1ll*fac[i-1]*i%mod;
	for(int i=0;i<N;++i)for(int j=C[i][0]=1;j<=i;++j)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	for(int i=0;i<N;++i)for(int j=0;j<N;++j)
	{
		T[i][j]=1;
		for(int k=0;k<j;++k)T[i][j]=1ll*T[i][j]*(i-k)%mod;
	}
}
void ATRI()
{
	int n,m;cin>>n>>m>>s+1;
	for(int i=1;i<=n;++i)a0[i]=a0[i-1]+(s[i]=='0'),a1[i]=a1[i-1]+(s[i]=='1');
	for(int i=1,x;i<=n;++i)cin>>x,++cnt[x];
	for(int i=0;i<=n;++i)sc[i]=(i?sc[i-1]:0)+cnt[i];
	f[0][0][cnt[0]]=1;
	for(int i=0;i<n;++i)for(int j=0;j<=i;++j)for(int k=0;k<=n;++k)if(f[i][j][k])
		if(s[i+1]=='0')
		{
			int w=i-(sc[j]-k);
			for(int l=0;l<=cnt[j+1];++l)
			{
				int coe=C[cnt[j+1]][l];
				coe=1ll*coe*T[w][l]%mod;
				add(f[i+1][j+1][k+cnt[j+1]-l-1],1ll*coe*k%mod*f[i][j][k]%mod);
			}
			for(int l=0;l<=cnt[j+1];++l)
			{

				int coe=C[cnt[j+1]][l];
				coe=1ll*coe*T[w][l]%mod;
				add(f[i+1][j+1][k+cnt[j+1]-l],1ll*coe%mod*f[i][j][k]%mod);
			}
			for(int l=0;l<=cnt[j+1];++l)
			{

				int coe=1ll*C[cnt[j+1]][l+1]*(l+1)%mod;
				coe=1ll*coe*T[w][l]%mod;
				add(f[i+1][j+1][k+cnt[j+1]-l-1],1ll*coe%mod*f[i][j][k]%mod);
			}
		}
		else 
		{
			int w=i-(sc[j]-k);
			for(int l=0;l<=cnt[j+1];++l)
			{

				int coe=C[cnt[j+1]][l];
				coe=1ll*coe*T[w][l]%mod;
				add(f[i+1][j+1][k+cnt[j+1]-l-1],1ll*coe*k%mod*f[i][j][k]%mod);
			}
			add(f[i+1][j][k],f[i][j][k]%mod);
		}
	int ans=0;
	for(int i=0;i<=n-m;++i)for(int k=0;k<=n;++k)if(f[n][i][k])
	{
		int w=n-(sc[i]-k),s=n-sc[i];
		if(k>=0&&w>=0)add(ans,1ll*C[s][w]*fac[w]%mod*f[n][i][k]%mod);
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	init();ATRI();
	return 0;
}