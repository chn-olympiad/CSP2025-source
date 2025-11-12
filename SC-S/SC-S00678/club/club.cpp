#include <bits/stdc++.h>
using namespace std;

const int N1=205,N=1e5+100;
long long dp1[N1][N1][N1];
int a[N][5];
int T,n;
int k[N],best[N],sec_best[N],bestid[N],sec_bestid[N],cnt[5];
bool cmp(int a,int b){
	return best[a]-sec_best[a]>best[b]-sec_best[b];
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	int q;
	long long ans=0;
	while(T--){
		ans=0;
		scanf("%d",&n);
		for(int i=1; i<=n; i++){
			for(int j=1; j<=3; j++){
				scanf("%d",&a[i][j]);
			}
		}
		
		if(n<=200){
			dp1[0][0][0]=0;
			for(int i=1; i<=n; i++){
				for(int j=0; j<=(n+1)/2; j++){
					for(int k=0; k<=(n+1)/2&&k+j<=i; k++){
						if((i-j-k)>(n+1)/2)continue;
						q=i-j-k;
						dp1[j][k][q]=0;
						if(j>0)dp1[j][k][q]=max(dp1[j][k][q],dp1[j-1][k][q]+a[i][1]);
						if(k>0)dp1[j][k][q]=max(dp1[j][k][q],dp1[j][k-1][q]+a[i][2]);
						if(q>0)dp1[j][k][q]=max(dp1[j][k][q],dp1[j][k][q-1]+a[i][3]);
						if(i==n)ans=max(ans,dp1[j][k][q]);
						
						//printf("-----%d %d %d %lld\n",j,k,q,dp1[j][k][q]);
					}
				}
			}
			printf("%lld\n",ans);
		}else{
			memset(best,0,sizeof(best));
			memset(sec_best,0,sizeof(sec_best));
			memset(bestid,0,sizeof(bestid));
			memset(sec_bestid,0,sizeof(sec_bestid));
			memset(cnt,0,sizeof(cnt));
			
			for(int i=1; i<=n; i++){
				bestid[i]=1,sec_bestid[i]=2;
				for(int j=1; j<=3; j++){
					if(a[i][j]>best[i]){
						sec_best[i]=best[i];
						sec_bestid[i]=bestid[i];
						best[i]=a[i][j];
						bestid[i]=j;
					}else if(a[i][j]>sec_best[i]){
						sec_best[i]=a[i][j];
						sec_bestid[i]=j;
					}
				}
			}
			
			for(int i=1; i<=n; i++)k[i]=i;
			sort(k+1,k+1+n,cmp);
			//for(int i=1; i<=n; i++)cout<<k[i]<<endl;
			
			for(int i=1; i<=n; i++){
				if(cnt[bestid[k[i]]]<n/2){
					ans+=best[k[i]];
					cnt[bestid[k[i]]]++;
				}else{
					ans+=sec_best[k[i]];
					cnt[sec_bestid[k[i]]]++;
				}
			}
			
			printf("%lld\n",ans);
		}
	}
	return 0;
}