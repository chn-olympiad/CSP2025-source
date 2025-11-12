#include<bits/stdc++.h>
using namespace std;
struct no{
	long long v,w,nxt;
}lian[3000010];
long long head[5000],cn=1,n,m,u,v,w,pol[20][1010],xiu[114],f;
void add(int u,int v,int w){
	cn++;
	lian[cn]={v,w,head[u]};
	head[u]=cn;
	cn++;
	lian[cn]={u,w,head[v]};
	head[v]=cn;
}//cn from 1!
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		add(u,v,w);
	}
	for(int j=1;j<=k;j++){//Pol Pot is very happy!
		scanf("%lld",&xiu[j]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&pol[i][j]);
			if(pol[i][j]!=0){
				f=1;
			}
		}
		if(xiu[j]!=0){
			f=1;
		}
	}
	if(!f&&k){
		printf("0");
		return 1;
	}
	return 0;
}
//rp=pow(114514,1919810)!;