#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
const long long mod=998244353;

int n,m,s[maxn],c[maxn],p[maxn],sum;
long long pw[maxn];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%1d",&s[i]);
		sum+=s[i];
	}
	for (int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	if (n<=10){
		for (int i=1;i<=n;i++){
			p[i]=i;
		}
		long long ans=0;
		do{
			int giv=0;
			for (int i=1;i<=n;i++){
				if (s[i]==0 || giv>=c[p[i]]){
					giv++;
				}
			}
			if (n-giv>=m){
				ans=(ans+1)%mod;
			}
		}while (next_permutation(p+1,p+n+1));
		printf("%lld",ans);
	}else if (sum==n){
		long long ans=1;
		for (int i=2;i<=n;i++){
			ans=ans*i%mod;
		}
		printf("%lld",ans);
	}else{
		printf("0");
	}
	return 0;
}
