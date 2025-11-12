#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int N=1e6+10;
int n,m,k,tot=0,head[N],fas[N];
struct node{
	int u,v,nex,num;
}e[N];
void add(int x,int y,int z){
	e[++tot]=(node){x,y,head[x],z};
	head[x]=tot;
}
int finds(int x){
	if(x==fas[x]) return x;
	return fas[x]=finds(fas[x]);
}
void unions(int x,int y){
	fas[x]=y;
}
priority_queue<pair<int,int> >q;
priority_queue<pair<int,int> >p;
int f,g,h,o[N],c,num=0,ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) fas[i]=i; 
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&f,&g,&h);
		add(f,g,h);
		q.push(make_pair(-h,tot));
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c);
		for(int j=1;j<=n;j++){
			scanf("%d",&o[j]);
			add(n+i,j,o[j]);
			q.push(make_pair(-o[j]-c,tot));
		} 
	}
	while(num<n-1){
		int idx=q.top().second,costs=-q.top().first;
		q.pop();
		int l=e[idx].u,r=e[idx].v;
		if(finds(l)==finds(r)) continue;
		unions(l,r);ans+=costs;++num;
	}
	
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
