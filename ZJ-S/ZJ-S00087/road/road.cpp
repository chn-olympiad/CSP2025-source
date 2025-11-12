#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v,w;
}a[1000010];
int n,m,k,f[10010],cnt,fx,fy;
long long s;
int find(int x){
	if(f[x]==x)return f[x];
	return f[x]=find(f[x]);
}
int cmp(node a,node b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(!k){
		for(int i=1;i<=n;++i)f[i]=i;
		for(int i=1;i<=m;++i)cin>>a[i].u>>a[i].v>>a[i].w;
		sort(a+1,a+m+1,cmp);
		for(int i=1;i<=m;++i){
			if(cnt==n-1)break;
			fx=find(a[i].u);fy=find(a[i].v);
			if(fx==fy)continue;
			f[fx]=fy;
			s+=a[i].w;
			++cnt;
		}
		cout<<s<<"\n";
	}
	else cout<<"0\n";
	return 0;
}
