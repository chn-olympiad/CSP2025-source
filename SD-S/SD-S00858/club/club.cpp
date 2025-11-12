#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e5+5;
int T,n;
long long d[N][5],num[5],cnt,a[N];
long long maxd[N],maxi[N],ans,nummax,nummaxi;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		cnt=0;ans=0;nummax=0;nummaxi=0;
		scanf("%d",&n);
		for(int i=1;i<=3;i++) num[i]=0;
		for(int i=1;i<=n;i++){
			maxd[i]=0;maxi[i]=0;a[i]=0;
			for(int j=1;j<=3;j++){
				scanf("%lld",&d[i][j]);
				if(maxd[i]<d[i][j]){
					maxd[i]=d[i][j];
					maxi[i]=j;
				}
			} 
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(j==maxi[i]){
					ans+=maxd[i];
					++num[j]; 
					if(num[j]>nummax){
						nummax=num[j];
						nummaxi=j;
					}
				}
			}
		}
		long long k=nummax;
		if(k>(n>>1)){
			for(int i=1;i<=n;i++){	
				if(maxi[i]==nummaxi){
				++cnt;a[cnt]=3e9+7;
					for(int j=1;j<=3;j++){
						if(j!=nummaxi) a[cnt]=min(a[cnt],maxd[i]-d[i][j]);
					}
				}
			}
			sort(a+1,a+cnt+1);
		}
		for(int i=1;i<=k-(n>>1);i++){
			ans-=a[i];
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
