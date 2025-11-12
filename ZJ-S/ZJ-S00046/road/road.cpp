#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int u,v,w;
}egs[1000010];
int ret[11111],a[11][11111],c[11],n,m,k;
int find(int x){
	return ret[x]=ret[x]==x?x:find(ret[x]);
}
void hb(int x,int y){
	ret[find(x)]=find(y);
}
bool cmp(node a,node b){
	return a.w<b.w;
}
void kr(){
	int res=0,cnt=0;
	for (int i=1;i<=m;++i){
		int u=egs[i].u,v=egs[i].v;
		if (find(u)!=find(v)){
			hb(u,v);
			res+=egs[i].w;
			cnt+=1;
		}
		if (cnt==n-1){
			break;
		}
	}
	cout<<res<<endl;
}
signed main(){
	cin>>n>>m>>k;
	for (int i=1;i<=n;++i){
		ret[i]=i;
	}
	for (int i=1;i<=m;++i){
		cin>>egs[i].u>>egs[i].v>>egs[i].w;
	}
	bool f=0;
	for (int i=1;i<=k;++i){
		cin>>c[i];
		if (c[i]!=0)f=1;
		for (int j=1;j<=n;++j){
			cin>>a[i][j];
			if (a[i][j]!=0)f=1;
		}
	}
	if (!f){
		cout<<0<<endl;
		return 0;
	}
	sort(egs+1,egs+1+m,cmp);
	kr();
	return 0;
}
