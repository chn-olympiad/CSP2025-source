#include<bits/stdc++.h>
using namespace std;
int n;
long long mx;
struct node{
	int a,b,c;
}x[100005];
int v[100005],u;
void dfs(int w,long long sum,int a,int b,int c){
	if(w>n){
		if(mx<sum){
			mx=max(mx,sum);
//			printf("%2d:",sum);
//			for(int i=1;i<w;i++){
//				printf("%d ",v[i]);
//			}
//			printf("\n");
		}
		return ;
	}
	if(a<(n/2)){
		v[w]=1;
		dfs(w+1,sum+x[w].a,a+1,b,c);
	}
	if(b<(n/2)){
		v[w]=2;
		dfs(w+1,sum+x[w].b,a,b+1,c);
	}
	if(c<(n/2)){
		v[w]=3;
		dfs(w+1,sum+x[w].c,a,b,c+1);
	}
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		mx=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
		scanf("%d%d%d",&x[i].a,&x[i].b,&x[i].c);
		}
		dfs(1,0,0,0,0);
		printf("%d\n",mx);
	}
	return 0;
}
