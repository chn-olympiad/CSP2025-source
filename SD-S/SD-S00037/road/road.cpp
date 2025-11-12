#include<bits/stdc++.h>
#define ll long long
using namespace std;
int f[10003];
struct node{
	int v,u,w;
}a[1000004];
void F(int t,int v){
	if(f[t]==t){
		f[t]=v;
		return ;
	}
	F(f[t],v);
	f[t]=f[f[t]];
}
void fin(int t){
	if(f[t]==t){
		return ;
	}
	fin(f[t]);
	f[t]=f[f[t]];
}
bool cmp(node a,node b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1;i<=n;i++){
			f[i]=i;
		}
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
			if(a[i].u>a[i].v){
				swap(a[i].u,a[i].v);
			}
		}
		sort(a+1,a+1+m,cmp);
		ll sum=0;
		for(int i=1;i<=m;i++){
			fin(a[i].v);
			fin(a[i].u);
			if(f[a[i].v]!=f[a[i].u]){
				sum+=a[i].w;
				F(a[i].u,a[i].v);
			}
		}
		cout<<sum;
	}
	else{
		cout<<0;
	}
	
	return 0;
} 
