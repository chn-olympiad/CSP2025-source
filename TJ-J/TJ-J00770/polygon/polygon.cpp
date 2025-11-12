#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>

template <typename T>
bool tense(T &a,const T &b){
	if(a>b){
		a=b;
		return true;
	}return false;
}
template <typename T>
bool relax(T &a,const T &b){
	if(a<b){
		a=b;
		return true;
	}return false;
}

int a[100005];
namespace Force{
	int n;
	const int maxn=105;

	void solve(int _n){
		n=_n;
		
		
		int ans=0;
		for(int s=0;s<(1<<n);s++){
			int cnt=0,c=0,cmax=0;
			for(int i=1;i<=n;i++) if(s>>(i-1)&1){
				c+=a[i];
				cnt++;
				relax(cmax,a[i]);
			}

			if(cnt>=3&&c>cmax*2) ans++;
		}
		printf("%d\n",ans%998244353);
	}
}

namespace Spc{
	int n;
	const int maxn=5005,MOD=998244353;
	int C[maxn][maxn];
	void solve(int _n){
		n=_n;
		C[0][0]=C[0][1]=C[1][0]=C[1][1]=1;
		for(int i=2;i<=n;i++){
			C[i][1]=i;
			for(int j=2;j<=i;j++){
				C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
			}
		}
		
		int ans=0;
		for(int i=3;i<=n;i++) ans+=C[n][i],ans%=MOD;
		printf("%d\n",ans); 
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	bool is=true;
	for(int i=1;i<=n;i++) if(a[i]!=1) is=false;
	if(is) Spc::solve(n);
	else Force::solve(n);
	return 0;
}