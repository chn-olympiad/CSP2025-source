#include<bits/stdc++.h>
using namespace std;
int n,t,sumaa,sumbb,sumcc,anss;
int o[10];
struct node{
	int a,b,c;
}a[20005];
void dfs(int t,int sum){
	if(t==n+1){
		anss=max(anss,sum);
		return;
	}
	if(sumaa+1<=n/2){
		sumaa++;
		dfs(t+1,sum+a[t].a);
		sumaa--;
	}
	if(sumbb+1<=n/2){
		sumbb++;
		dfs(t+1,sum+a[t].b);
		sumbb--;
	}
	if(sumcc+1<=n/2){
		sumcc++;
		dfs(t+1,sum+a[t].c);
		sumcc--;
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int mp=1;mp<=t;mp++){
		scanf("%d",&n);
		sumaa=sumbb=sumcc=anss=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
		}
		dfs(1,0);
		o[mp]=anss;
	}
	for(int i=1;i<=t;i++)printf("%d\n",o[i]);
	return 0;
}
