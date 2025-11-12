#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N][3];
int w[3]={};
int ans[3]={};
struct node{
	int dte;
	int id;
};
int use[N]={};
inline void init(){
	memset(a,0,sizeof(a));
	memset(use,0,sizeof(use));
}
inline int dfs(int x,int cnt){
	if(max({use[0],use[1],use[2]})>n/2)return 0;
	if(x==n+1)return cnt;
	int ret=0;
	for(int i=0;i<3;i++){
		use[i]++;
		ret=max(ret,dfs(x+1,cnt+a[x][i]));
		use[i]--;
	}
	return ret;
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		init();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		}
		cout<<dfs(1,0)<<"\n";
	}
	return 0;
}