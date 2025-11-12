#include<bits/stdc++.h>
using namespace std;
long long read(){
	char c=getchar();
	long long s=0;
	while(c<'0' || c>'9'){
		c=getchar();
	}
	while(c>='0' && c<='9'){
		s=(s<<1)+(s<<3)+int(c-'0');
		c=getchar();
	}
	return s;
}
class node{
	public:
		long long u,v,k;
};
node nd[100005];
bool cmp(node A,node B){
	return A.k<B.k;
}
long long n,m,k,fa[10005],c[15],a[15][10005],sum,Aa,Bb;
long long fd(int x){
	return (x==fa[x])?(x):(fa[x]=fd(fa[x]));
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++){
		nd[i].u=read();
		nd[i].v=read();
		nd[i].k=read();
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			a[i][j]=read();
		}
	}
	sort(nd+1,nd+1+m,cmp);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cout<<fa[j]<<" ";
		}
		cout<<endl;
		fa[nd[i].u]=fd(nd[i].u);fa[nd[i].v]=fd(nd[i].v);
		if(fa[nd[i].u]==fa[nd[i].v]){
			continue;
		}
		else{
			sum+=nd[i].k;
			fa[fa[nd[i].u]]=fa[fa[nd[i].v]];
		}
	}
	for(int i=1;i<=n;i++){
		cout<<fa[i]<<" ";
	}
	cout<<endl;
	cout<<sum;
	return 0;
}
