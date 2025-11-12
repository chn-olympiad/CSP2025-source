#include<bits/stdc++.h>
using namespace std;
int n,m,k,c,d,b[100005],fa[100005],s;
struct node{
	int u,v,w;
}a[1000005];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(x==fa[x]) return x;
	else return find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	d=n;
	if(k==0){
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<=m;i++){
			int x=a[i].u,y=a[i].v,z=a[i].w;
			int fx=find(x),fy=find(y);
			if(fx!=fy){
				c++;
				s+=z;
				fa[fx]=fy;
				if(c==n-1){
					cout<<s;
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
