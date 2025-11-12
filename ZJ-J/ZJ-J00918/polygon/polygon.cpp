#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005,mod=998244353;
bool f=1;
int n,a[N],ans,cnt,sum,maxn=-1;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=1) f=0;
	}
	if(f){
		vector<vector<int> > C(n+2,vector<int>(n+2));
		C[1][1]=1;
		for(int i=2;i<=n+1;i++){
			for(int j=1;j<=i;j++){
				C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
			}
		}
		for(int i=3;i<=n;i++){
			ans=(ans+C[n+1][i+1])%mod;
		}
		printf("%lld\n",ans%mod);
		return 0;
	}
	for(int i=0;i<=(1<<n)-1;i++){
		cnt=0,sum=0,maxn=-1;
		for(int j=1;j<=n;j++){
			if(i&(1<<(j-1))){
				cnt++;
				sum+=a[j];
				maxn=max(maxn,a[j]);
			}
		}
		if(cnt>=3&&sum>2*maxn) ans=(ans+1)%mod;
	}
	printf("%lld\n",ans%mod);
	
	return 0;
}

