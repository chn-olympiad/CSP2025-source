#include<bits/stdc++.h>
using namespace std;

int n,m,k,t;
struct Edge{
	int from,to,vila;
	long long dis;
}e[3300000];
int u,v;
long long w;
int fa[10100][1024];
int c[20];
long long ans[2030],answer;
bool flag=false,flag1;

int find(int x,int y){
	if(fa[x][y]==x) return x;
	fa[x][y]=find(fa[x][y],y);
	return fa[x][y];
}

int unit(int x1,int x2,int y){
	fa[find(x1,y)][y]=fa[find(x2,y)][y];
}

bool cmp(Edge x,Edge y){
	return x.dis<y.dis;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%d%d%lld",&u,&v,&w);
		e[++t].from=u-1,e[t].to=v-1,e[t].dis=w,e[t].vila=12;
	}
	for(int i=0;i<k;i++){
		scanf("%d",&c[i]);
		if(c[i]!=0) flag=true;
		flag1=false;
		for(int j=0;j<n;j++){
			e[++t].from=n+i,e[t].to=j,e[t].vila=i;
			scanf("%d",&w);
			e[t].dis=w;
			if(w==0) flag1=true;
		}
		if(flag1==false) flag=true;
	}
	sort(e+1,e+t+1,cmp);
	for(int i=0;i<n+k;i++)
		for(int j=0;j<(1<<k);j++)
			fa[i][j]=i;
	int s;
	for(int i=1;i<=t;i++){
		s=e[i].vila,u=e[i].from,v=e[i].to,w=e[i].dis;
		for(int j=0;(j<(1<<k))&&(flag||j==0);j++)
			if(s==12||((j&(1<<s))!=0)||(!flag))
				if(find(u,j)!=find(v,j)){
					unit(u,v,j);
					ans[j]+=w;
					//cout<<s<<" "<<u<<" "<<v<<" "<<w<<" "<<j<<" "<<ans[j]<<"\n";
				}
	}
	for(int j=0;j<(1<<k);j++)
		for(int i=0;i<k;i++)
			if((j&(1<<i))!=0) ans[j]+=c[i];
	answer=ans[0];
	//cout<<k<<" "<<(1<<k)<<"\n";
	for(int j=1;j<(1<<k);j++){
		//printf("%d\n",ans[j]);
		if(ans[j]<answer&&(flag)){
			answer=ans[j];
		}
	}
	printf("%lld\n",answer);
	return 0;
}
