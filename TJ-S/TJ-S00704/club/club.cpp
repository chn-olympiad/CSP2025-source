#include<bits/stdc++.h>
using namespace std;
int n,T,suma,sumb,sumc,ans;
int o[10];
struct node{
	int a,b,c,cam,maxn,p;
}a[20005];
void dfs(int t,int sum){
	if(t==n+1){
		ans=max(ans,sum);
		return;
	}
	if(suma+1<=n/2){
		suma++;
		dfs(t+1,sum+a[t].a);
		suma--;
	}
	if(sumb+1<=n/2){
		sumb++;
		dfs(t+1,sum+a[t].b);
		sumb--;
	}
	if(sumc+1<=n/2){
		sumc++;
		dfs(t+1,sum+a[t].c);
		sumc--;
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	for(int mp=1;mp<=T;mp++){
		scanf("%d",&n);
		suma=sumb=sumc=ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
		}
		dfs(1,0);
		o[mp]=ans;
	} 
	for(int i=1;i<=T;i++)printf("%d\n",o[i]);
	return 0;
}
