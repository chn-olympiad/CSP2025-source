#include<bits/stdc++.h>
using namespace std;
int t,n,x,y,z,ans;
vector<vector<int> > a(10010,vector<int>(5)); 
void dfs(int s1,int s2,int s3,int cnt,int start){
	if(s1>n/2||s2>n/2||s3>n/2) return;
	if(start>n){
		ans=max(ans,cnt);
		return;
	}for(int i=start;i<=n;i++){
		dfs(s1+1,s2,s3,cnt+a[i][1],i+1);
		dfs(s1,s2+1,s3,cnt+a[i][2],i+1);
		dfs(s1,s2,s3+1,cnt+a[i][3],i+1);
	}return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=INT_MIN;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		dfs(0,0,0,0,0);
		printf("%d\n",ans);
	}
	return 0; 
}