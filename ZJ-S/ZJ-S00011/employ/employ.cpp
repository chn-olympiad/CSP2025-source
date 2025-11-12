#include<cstdio>
#define ll long long
using namespace std;
const ll mod=998244353;
const ll M=5e5+5,N=505;
bool a[N];
int c[N];
ll f[M][20];int n,m;
void work1(){
	int t=(1<<n)-1;
	f[0][0]=1;
	for(int i=0;i<=t;i++){
		int rc=1;
		for(int k=0;k<n;k++){
			if(i&(1<<k)) rc++;
		}
//		if(rc>n-m+1) continue;
		for(int j=0;j<=rc;j++){
			if(f[i][j]==0) continue;
			for(int k=1;k<=n;k++){
				if(i&(1<<(k-1))){
					continue;
				}
				
				int v=0;
				if(j>=c[k] || a[rc]==0) v++;
				f[i+(1<<(k-1))][j+v]=(f[i+(1<<(k-1))][j+v]+f[i][j])%mod;
			}
		}
	}
	ll ans=0;
	for(int i=0;i<=n-m;i++){
		ans+=f[t][i];
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		char ch=0;
		while(ch!='0' && ch!='1') scanf("%c",&ch);
		a[i]=ch-'0';
	}
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	if(n<=18){
		work1();
		return 0;
	}
	
	
	
	return 0;
}

