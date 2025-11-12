#include<cstdio>
int dp[10015][10015],a,b,c,n,m,k,w,p,q,ans1,df,ans=2147483647,visit[10015],flag;
int min(int a,int b){
	return (a<b?a:b);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n+k;i++){
			for(int j=1;j<=n+k;j++){
				dp[i][j]=2147483647;
			}
		}
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&a,&b,&w);
		dp[a][b]=min(dp[a][b],w);
		dp[b][a]=min(dp[b][a],w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c);
		for(int j=1;j<=n;j++){
			scanf("%d",&w);
			if(c==0||w==0){
				printf("0");return 0;
			}
		}
	}
	for(int d=1;d<=n;d++){
		ans1=0;
		visit[d]=1;
		flag=1;
		for(int i=d;flag;i=q){
			flag=0;
			p=2147483647;
			for(int j=1;j<=n;j++){
				if(visit[j]<=n&&visit[i]!=-1&&p>dp[i][j]){
					q=j;
					p=visit[j]==0?dp[i][j]:0;
					if(p==0){
						df=visit[i];
						visit[i]=-1;
						break;
					}
				}
			}
			visit[q]++;
			if(p==2147483647){
				ans1=2147483647;
				break;
			}
			ans1+=p;
			for(int j=1;j<=n;j++){
				if(!visit[j]){
					flag=1;
					break;
				}
			}
			if(visit[i]==-1){
				visit[i]=n+1;
			}
		}
		for(int i=1;i<=n+k;i++){
			visit[i]=df-1;
		}
		ans=min(ans,ans1);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
