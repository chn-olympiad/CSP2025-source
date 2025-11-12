#include<bits/stdc++.h>
using namespace std;
int n,m,k,sum=0;
struct Fode{
	int x;
	int y;
	int step;
	int f;
}fa[100005];
int arr[10005]={};
void init(){
	for(int i=1;i<=n;i++){
		fa[i].f=i;
	}
}
int c(int x){
	if(fa[x].f==x) return x;
	else fa[x].f=c(fa[x].f);
}
void merge(int x,int y){
	x=c(x);
	y=c(y);
	if(x!=y){
		fa[y].f=x;
	}
}
bool cmp(Fode a,Fode b){
	return a.step<b.step;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","r",stdout);
	cin>>n>>m>>k;
	init();
	for(int i=1;i<=m;i++){
		cin>>fa[i].x>>fa[i].y>>fa[i].step;
		merge(arr[fa[i].x],arr[fa[i].y]);
	}
	sort(fa+1,fa+m+1,cmp);
	for(int i=2;i<=n;i++){
		if(c(arr[i])!=c(arr[i-1])){
			sum+=fa[arr[i]].step;
			merge(arr[i],arr[i-1]);
		}
	}
	cout<<sum;
	//没招了，瞎写的，想蹭点分 ，我第一题写了3个多小时，后面不会了 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
