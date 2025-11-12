#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int s[501],c[501],f[1000000][20];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,ch=1,cnt=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%1d",&s[i]);
		ch&=s[i];
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	if(n==m){
		if(!ch){
			printf("0");
			return 0;
		}
		int sum=1;
		for(int i=1;i<=n;i++){
			if(!c[i]){
				printf("0");
				return 0;
			}
			sum=1ll*sum*i%mod;
		}
		printf("%d",sum);
		return 0;
	}
	if(n<=18){
		f[0][0]=1;
		for(int i=1;i<1<<n;i++){
			for(int j=0;j<n;j++){
				if((i>>j)&1)	cnt++;
			}
			int t=min(cnt,n-m);
			for(int j=1;j<=n;j++){
				if((i>>j-1)&1){
					if(s[cnt]){
						for(int k=0;k<c[j] && k<=t;k++){
							f[i][k]=(f[i][k]+f[i-(1<<j-1)][k])%mod;
						}
						for(int k=c[j]+1;k<=t;k++){
							f[i][k]=(f[i][k]+f[i-(1<<j-1)][k-1])%mod;
						}
					}
					else{
						for(int k=1;k<=t;k++){
							f[i][k]=(f[i][k]+f[i-(1<<j-1)][k-1])%mod;
						}
					}
				}
			}
			cnt=0;
		}
		for(int i=0;i<=n-m;i++){
			cnt=(cnt+f[(1<<n)-1][i])%mod;
		}
		printf("%d",cnt);
		return 0;
	}
	printf("114514");
	return 0;
}
