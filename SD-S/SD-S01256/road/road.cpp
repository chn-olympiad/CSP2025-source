#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k,f[10005],fx,ans;
struct node{
	int x,y,z;
}a[N];
bool cmp(node xx,node yy){
	return xx.z<yy.z;
}
int find(int x){
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[i]={u,v,w};
	}
	if(k){
		for(int i=1;i<=n;++){
			int x;
			cin>>x;
			for(int j=1;j<=n;j++){
				cin>>x;
			}
		}
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		int xx=find(a[i].x),yy=find(a[i].y);
		if(xx==yy){
			continue;
		}
		fx++;
		f[yy]=f[xx];
		ans+=a[i].z;
		if(fx==n-1){
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}
