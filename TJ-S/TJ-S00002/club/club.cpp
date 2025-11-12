#include<bits/stdc++.h>
using namespace std;
int Max=0,n=0;
int h[4];
void dfs(int a[][4],bool v[],int num,int sum){
	if(num==n){
		Max=max(Max,sum);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			for(int j=1;j<=3;j++){
				if(h[j]+1<=n/2){
					v[i]=1;h[j]++;
					dfs(a,v,num+1,sum+a[i][j]);
					v[i]=0;h[j]--;
				}
			}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int a[n+1][4];bool v[n+1];
		for(int i=1;i<=n;i++){
			int j=0;
			scanf("%d",&a[i][++j]);
			scanf("%d",&a[i][++j]);
			scanf("%d",&a[i][++j]);
		}
		memset(h,0,sizeof(h));
		dfs(a,v,0,0);
		printf("%d\n",Max);Max=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
