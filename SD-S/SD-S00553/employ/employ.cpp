#include<iostream>
#include<cstdio>
#include<bitset>
using namespace std;
const int p=998244353;
const int N=510;
const int maxd=1e7;
int n,m,ans;
bitset<N> d,vis; 
int c[N],cnt;
void dfs1(int cur,int cnt,int sum){
	//printf("%d %d %d\n",cur,cnt,sum);
//	cnt++;
//	if(cnt>maxd) return ;
	if(cur>=n+1){
		printf("%d\n",sum);
		if(sum>=m){
			//printf("+1!!!\n");
			ans=(ans+1)%p;
		} 
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			//printf("%d ",i);
			vis[i]=1;
			if(c[i]>cnt){
				if(!d[cur]) dfs1(cur+1,cnt+1,sum);
				else dfs1(cur+1,cnt,sum+1);
			} 
			else dfs1(cur+1,cnt,sum);
			vis[i]=0;
			//printf("\n");
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		char x;
		cin>>x;
		if(x-'0') d[i]=1;
		else d[i]=0;
	}
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	dfs1(1,0,0);
	printf("%d\n",ans);
	return 0;
}
