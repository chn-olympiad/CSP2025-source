#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+5;
int t;
int n;
int a[N][4];
int mx=0;
void dfs(int x,int s1,int s2,int s3,int sum){
	if(x==n+1){
		mx=max(sum,mx);
		return ;
	}
	if(s1+1<=n/2)dfs(x+1,s1+1,s2,s3,sum+a[x][1]);
	if(s2+1<=n/2)dfs(x+1,s1,s2+1,s3,sum+a[x][2]);
	if(s3+1<=n/2)dfs(x+1,s1,s2,s3+1,sum+a[x][3]);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
			}
		}
		
		
		
		mx=0;
		dfs(1,0,0,0,0);
		printf("%d\n",mx);
	}
	return 0;
} 

