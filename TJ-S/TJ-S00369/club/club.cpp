#include<cstdio>
const int maxn=100005,INF=0x3f3f3f3f;
int a[maxn][4];
int t;
int n;
int len,ans,sum;
void dfs(){
	if(len==n){
		if(sum>ans) ans=sum;
		return;
	}
	len++;
	for(int i=1;i<=3;i++){
		if
		for(int j=len;j<=n;j++){ 
			sum+=a[len][i];
		}
		dfs();
		for(int j=len;j<=n;j++){
			sum-=a[len][i];
		}
	}
	len--;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
			}
		}
		len=0,ans=-INF,sum=0;
		dfs();
		printf("%d\n",ans);
	}
	return 0;
} 
