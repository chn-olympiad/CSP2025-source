#include <bits/stdc++.h>
using namespace std;
int n,kk;
int a[500005];
int dp[500005];
int tot;
struct node{
	int x,y,l;
}q[10000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&kk);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int ans=a[i];
			for(int k=i+1;k<=j;k++){
				ans^=a[k];
			}
			if(ans==kk){
				tot++;
				q[tot].x=i;
				q[tot].y=j;
				q[tot].l=j-i;
			}
		}
	}
	for(int j=1;j<=tot;j++){
		for(int i=1;i<=n;i++){
			if(i>=q[j].y)dp[i]=max(dp[i-1],max(dp[i],dp[q[j].x-1]+1));
		}
	}
	cout<<dp[n];
	return 0;
}
