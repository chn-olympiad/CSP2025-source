#include<bits/stdc++.h>
using namespace std;
int n,ans,a[100001][5],b[100001],q1[100001],q2[100001];
int dp[105][105][105];
void dfs(int now,int s1,int s2,int s3,int val){
	if(now>n){
		ans=max(ans,val);
		return;
	}
	if(s1<n/2)dfs(now+1,s1+1,s2,s3,val+a[now][1]);
	if(s2<n/2)dfs(now+1,s1,s2+1,s3,val+a[now][2]);
	if(s3<n/2)dfs(now+1,s1,s2,s3+1,val+a[now][3]);
}
bool cmp1(int u,int v){
	return a[u][1]-a[u][2]<a[v][1]-a[v][2];
}
bool cmp2(int u,int v){
	return a[u][2]-a[u][1]<a[v][2]-a[v][1];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int flag1=1,flag=1;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][3]!=0)flag=false;
			if(a[i][2]!=0||a[i][3]!=0)flag1=false;
		}
		if(flag1){
			int res=0;
			for(int i=1;i<=n;i++)b[i]=a[i][1];
			sort(b+1,b+n+1);
			for(int i=n/2+1;i<=n;i++)res+=b[i];
			printf("%d\n",res);
			continue;
		}
		else if(flag){
			int top1=0,top2=0;
			for(int i=1;i<=n;i++)
				if(a[i][1]>a[i][2])q1[++top1]=i;
				else q2[++top2]=i;
			if(top1>n/2){
				sort(q1+1,q1+top1+1,cmp1);
				int res=0,l=top1-n/2;
				for(int i=1;i<=l;i++)res+=a[q1[i]][2];
				for(int i=l+1;i<=top1;i++)res+=a[q1[i]][1];
				for(int i=1;i<=top2;i++)res+=a[q2[i]][2];
				printf("%d\n",res);
			}else if(top2>n/2){
				sort(q2+1,q2+top2+1,cmp2);
				int res=0,l=top2-n/2;
				for(int i=1;i<=l;i++)res+=a[q2[i]][1];
				for(int i=l+1;i<=top2;i++)res+=a[q2[i]][2];
				for(int i=1;i<=top1;i++)res+=a[q1[i]][1];
				printf("%d\n",res);
			}else{
				int res=0;
				for(int i=1;i<=top1;i++)res+=a[q1[i]][1];
				for(int i=1;i<=top2;i++)res+=a[q2[i]][1];
				printf("%d\n",res);
			}
			continue;
		}
		else if(n<=200){
			int res=0;
			for(int i=1;i<=n;i++)
				for(int j=1;j<=min(i,n/2);j++)
					for(int k=1;k<=min(i-j,n/2);k++){
						int p=i-j-k;
						if(p>(n/2))continue;
						dp[j][k][p]=max(max(dp[j][k][p],dp[j+1][k][p]+a[i][1]),max(dp[j][k+1][p]+a[i][2],dp[j][k][p+1]+a[i][3]));
					}
			for(int j=1;j<=n/2;j++)
				for(int k=1;k<=n/2;k++){
					int p=n-j-k;
					if(p>(n/2))continue;
					res=max(res,dp[j][k][p]);
				}
			printf("%d\n",res);
		}
		ans=0;
		dfs(1,0,0,0,0);
		printf("%d\n",ans);
	}
	return 0;
}
