#include<bits/stdc++.h>
using namespace std;
int n,m,k,c,aj[10004],ans=0,bj[10004],bccj[15][10004];
struct rd{
	int u,v,w;
}xf[1000006];
vector<int> lj[10004],lq[10004];
bool pd(rd a,rd b){
	return a.w<b.w;
}
int bcj(int bb){
	if(bj[bb]==bb){
		return bb;
	}return bj[bb]=bcj(bj[bb]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		bj[i]=i;
	}for(int i=0;i<m;i++){
		cin>>xf[i].u>>xf[i].v>>xf[i].w;
	}sort(xf,xf+m,pd);
	for(int i=0;i<m;i++){
		bj[xf[i].u]=bcj(bj[xf[i].u]);
		bj[xf[i].v]=bcj(bj[xf[i].v]);
		if(bj[xf[i].u]!=bj[xf[i].v]){
			bj[xf[i].u]=bj[xf[i].v];
			ans+=xf[i].w;
			lj[xf[i].u].push_back(xf[i].v);
			lj[xf[i].v].push_back(xf[i].u);
			lq[xf[i].u].push_back(xf[i].w);
			lq[xf[i].v].push_back(xf[i].w);
		}
	}for(int i=0;i<k;i++){
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>aj[j];
		}
	}cout<<ans;
}
