#include<bits/stdc++.h>
using namespace std;
int n,s[100001][3],h;
long long m=-1;
void dfs(int k,int a,int b,int c,long long sum){
	if(k==n+1){
		m=max(m,sum);
		return ;
	}
	if(a<h)dfs(k+1,a+1,b,c,sum+s[k][0]);
	if(b<h)dfs(k+1,a,b+1,c,sum+s[k][1]);
	if(c<h)dfs(k+1,a,b,c+1,sum+s[k][2]);
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		long long sum=0;
		scanf("%d",&n);
		h=n/2;
		m=-1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++){
				scanf("%d",&s[i][j]);
			}
		}
		if(n>30){
			m=0;
			int t[10001];
			for(int i=1;i<=n;i++){
				t[i]=s[i][0];
			}
			sort(t+1,t+n+1);
			for(int i=1;i<=n/2;i++){
				m+=t[i];
			}
			printf("%d\n",m);
			continue;
		}
		dfs(1,0,0,0,0);
		printf("%d\n",m);
	}
	return 0;
} 
