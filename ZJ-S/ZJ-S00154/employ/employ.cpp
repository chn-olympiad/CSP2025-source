#include<cstdio>
using namespace std;
const int N=505,p=998244353;
int n,m,c[N],pai[N],cnt;
char dif[N];
bool vis[N];
bool check(){
	int sum=0;
	for(int i=1;i<=n;++i){
		if(i-1-sum>=c[pai[i]]) continue;
		if(dif[i]=='1') ++sum;
	}
	return sum>=m?true:false;
}
void dfs(int now){
	if(now==n+1){
		if(check()){
			++cnt;
			cnt%=p;
		}
		return ;
	}
	for(int i=1;i<=n;++i){
		if(vis[i]) continue;
		pai[now]=i;
		vis[i]=true;
		dfs(now+1);
		vis[i]=false;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",dif+1);
	for(int i=1;i<=n;++i)
		scanf("%d",&c[i]);
	dfs(1);
	printf("%d",cnt);
	return 0;
}
