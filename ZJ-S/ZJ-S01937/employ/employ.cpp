#include<bits/stdc++.h>
#define P 998244353
#define int long long
using namespace std;
int n,m,sum,ans;
char s[502];
int a[502],b[502];
int f[20][300000];
int p[300000];
vector<int>c[20];
int lowbit(int x){return -x&x;}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld%s",&n,&m,s);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		b[i]=s[i-1]-'0';
		sum+=b[i];
	}
	if(sum<m){
		puts("0");
		return 0;
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			if(!a[i]){
				puts("0");
				return 0;
			}
		}
		ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans*i)%P;
		}
		printf("%lld\n",ans);
		return 0;
	}
	if(n<=18){
		int cst=(1<<n);
		c[0].push_back(0);
		for(int i=1;i<cst;i++){
			int st=i,ans=0;
			while(st){
				st-=lowbit(st);
				++ans;
			}
			p[i]=ans;
			c[ans].push_back(i);
		}
		f[0][0]=1;
		for(int i=1;i<=n;i++){
			for(int st:c[i-1]){
				for(int j=1;j<=n;j++){
					if(!(st&(1<<(j-1)))){
						if(!b[i]){
							for(int k=0;k<i;k++){
								f[k+1][st|(1<<j-1)]=(f[k+1][st|(1<<j-1)]+f[k][st])%P;
							}
						}else{
							for(int k=0;k<min(i,a[j]);k++){
								f[k][st|(1<<j-1)]=(f[k][st|(1<<j-1)]+f[k][st])%P;
							}
							for(int k=a[j];k<i;k++){
								f[k+1][st|(1<<j-1)]=(f[k+1][st|(1<<j-1)]+f[k][st])%P;
							}
						}
					}
				}
			}
		}
//		for(int i=1;i<=n;i++){
//			printf("%d:\n",i);
//			for(int j=0;j<=i;j++){
//				printf("    %d:\n",j);
//				for(int st:c[i]){
//					printf("        %d:%d\n",st,f[j][st]);
//				}
//			}
//		}
		for(int i=0;i+m<=n;i++){
			ans=(ans+f[i][cst-1])%P;
		}
		printf("%lld",ans);
		return 0;
	}
	puts("0");
	return 0;
}
/*

*/