#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int T;
int n;
int a[100005][4];
int sA[100005];
int sum=0,ans=-1145141919;

void dfs(int x,int f,int s,int t){
	if(x==n){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		if(f<n/2){
			sum+=a[x+1][1];
//			 cout<<a[x][1]<<" ";
			dfs(x+1,f+1,s,t);
			sum-=a[x+1][1];
		}
		if(s<n/2){
			sum+=a[x+1][2];
//			 cout<<a[x][2]<<" ";
			dfs(x+1,f,s+1,t);
			sum-=a[x+1][2];
		}
		if(t<n/2){
			sum+=a[x+1][3];
//			 cout<<a[x][3]<<" ";
			dfs(x+1,f,s,t+1);
			sum-=a[x+1][3];
		}
	}
}

int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		memset(a,0,sizeof a);
		int ai230=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
			}
			if(a[i][2]!=0||a[i][3]!=0) ai230=0;
		}
		if(ai230==1){
			for(int i=1;i<=n;i++) sA[i]=a[i][1];
			sort(sA+1,sA+n+1);
			int sAans=0;
			for(int i=n;i>n/2;i--)
				sAans+=sA[i];
			printf("%d\n",sAans);
			continue;
		}
		if(n<=10){
			sum=0;
			ans=-1145141919;
			dfs(0,0,0,0);
			printf("%d\n",ans);
		}
	}
	
	return 0;
}

//15pts.
//TAT
