#include<bits/stdc++.h>
using namespace std;
const long long maxm=1e6;
const long long maxn=1e4;
long long n,m,k,ans;
struct node{
	long long u,v,w;
}a[maxm+1];
bool cmp(node x,node y){
	return x.w<y.w;
}
long long fa[maxn+1];
//long long ans;
long long find(long long x){
	if(fa[x]==x){
		return x;
	}
	else{
		fa[x]=find(fa[x]);
		return fa[x];
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
srand(time(0));
cin>>n>>m>>k;
for(int i=1;i<=m;i++){
	cin>>a[i].u>>a[i].v>>a[i].w;
}
sort(a+1,a+m+1,cmp);
for(int i=1;i<=n;i++){
	fa[i]=i;
}
for(int i=1;i<=m;i++){
	long long Fa,fb;
	Fa=find(a[i].u);
	fb=find(a[i].v);
	if(Fa==fb){
		continue;
	}
	else{
		ans+=a[i].w;
		fa[Fa]=fb;
	}
}
cout<<ans;
return 0;
}
