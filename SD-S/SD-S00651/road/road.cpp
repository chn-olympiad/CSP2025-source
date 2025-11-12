#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct Node{
	int u,v;
	long long w;
}edge[2000005],edge1[2000005];
long long kw[15][10005];
int bi[20005];
bool pian;
int find(int x){
	int xx=x,z;
	while(bi[x]!=0){
		x=bi[x];
	}
	while(bi[xx]!=0){
		z=bi[xx];
		bi[xx]=x;
		xx=z;
	}
	return x;
}
void merge(int x,int y){
	int xx=find(x);
	int yy=find(y);
	bi[yy]=xx;
}
bool cmp(const Node xx,const Node yy){
	return xx.w<yy.w;
}
long long work1(int mm,int nn,long long sum){
	memset(bi,0,sizeof(bi));
	for(int i=1;i<=mm;i++){
		edge1[i].u=edge[i].u;
		edge1[i].v=edge[i].v;
		edge1[i].w=edge[i].w;
	}
//	for(int i=1;i<=mm;i++){
//		printf("%d %d %d\n",edge1[i].u,edge1[i].v,edge1[i].w);
//	}
	sort(edge1+1,edge1+mm+1,cmp);
	int count=1;
	int tot=1;

	while(count<nn){
		int uu=edge1[tot].u;
		int vv=edge1[tot].v;
		long long ww=edge1[tot].w;
//		printf("%d %d %d\n",uu,vv,ww);
		if(find(uu)!=find(vv)){
			count++;
			merge(uu,vv);
			sum+=ww;
		}
		tot++;
	}
	return sum;
}
long long work(int dep,int mm,int nn,long long sum){
	if(dep>k){
		return work1(mm,nn,sum);
	}
	long long ans1,ans2;
	for(int i=1;i<=n;i++){
		mm++;
		edge[mm].u=n+dep;
		edge[mm].v=i;
		edge[mm].w=kw[dep][i];
	}
	nn++;
	ans1=work(dep+1,mm,nn,sum+kw[dep][0]);
	//printf("%d ans1=%d\n",dep,ans1);
	mm-=n;
	nn--;
	if(!pian){
			ans2=work(dep+1,mm,nn,sum);
	}else{
		return ans1;
	}

	//printf("%d ans2=%d %d %d\n",dep,ans2,mm,nn);
	return min(ans1,ans2);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	
	for(int i=1;i<=m;i++){
		scanf("%d%d%lld",&edge[i].u,&edge[i].v,&edge[i].w);
	}
	pian=true;
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			scanf("%lld",&kw[i][j]);
			if(j==0&&kw[i][j]!=0) pian=false;
		}
	}
	printf("%lld",work(1,m,n,0));
	fclose(stdin);
	fclose(stdout);
	return 0;
}


