#include<cstdio>
#include<algorithm>
using namespace std;
int head[100005],vis[100005];
int cnt,s;
struct edge{
	int to,next,value;
}e[100005];
void add(int from,int to,int value){
	cnt++;
	e[cnt].to=to;
	e[cnt].value=value;
	e[cnt].next=head[from];
	head[from]=cnt;
	return;
}
void dfs(int k){
	if(vis[k]!=0)return;
	vis[k]=1;
	int f=head[k];
	for(int i=f;i;i=e[f].next){
		if(vis[i]==0){
			s+=e[f].value;
			dfs(e[i].to);
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,u,v,value;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%d %d %d",&u,&v,&value);
		add(u,v,value);
		add(v,u,value);
		//TODO
	}
	dfs(1);
	printf("%d",s);
	fclose(stdin);
	fclose(stdout);
	return 0;
}