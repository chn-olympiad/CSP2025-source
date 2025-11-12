#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,k,ans,idx=1;
struct node{
	long long s,e,w;
}val[1000005];
int vis[10005];
long long lj[10005][10005];
bool cmp(node a,node b){
	return a.w<b.w;
}
int find(int q){
	if(vis[q]==q) return q;
	else{
		vis[q]=find(vis[q]);
		return vis[q];
	}
}
void hb(int q1,int q2){
	vis[find(q1)]=vis[find(q2)];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int f,t,v;
		cin>>f>>t>>v;
		lj[f][t]=v;
		if(i<=n) vis[i]=i;
	}
	if(k!=0){
		for(int i=1;i<=k;i++){
			int c;
			long long xc[10005];
			cin>>c;
			for(int j=1;j<=n;j++){
				cin>>xc[j];
				for(int o=1;o<j;o++){
					lj[o][j]=min(lj[o][j],xc[o]+xc[j]);	
				}
			}
		}
	}
	for(int i=1;i<=10000;i++){
		for(int j=1;j<=10000;j++){
			if(lj[i][j]!=0){
				val[idx].s=i;
				val[idx].e=j;
				val[idx++].w=lj[i][j];
			}
		}
	}
	sort(val+1,val+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(find(val[i].s)!=find(val[i].e)){
			ans+=val[i].w;
			hb(val[i].s,val[i].e);
		}
	}
	cout<<ans<<endl;
	
	return 0;
}

