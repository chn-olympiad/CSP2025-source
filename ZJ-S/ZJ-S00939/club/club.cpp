#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N][4],ans;
void dfs(int l1,int l2,int l3,int sum){
	if(l1+l2+l3==n){
		ans=max(ans,sum);
		return;
	}
	if(l1<n/2)
		dfs(l1+1,l2,l3,sum+a[l1+l2+l3+1][1]);
	if(l2<n/2)
		dfs(l1,l2+1,l3,sum+a[l1+l2+l3+1][2]);
	if(l3<n/2)
		dfs(l1,l2,l3+1,sum+a[l1+l2+l3+1][3]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	short t;
	scanf("%hd",&t);
	while(t--){
		scanf("%d",&n),ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				scanf("%d",&a[i][j]);
		dfs(0,0,0,0);
		printf("%d\n",ans);
	}
	return 0;
}