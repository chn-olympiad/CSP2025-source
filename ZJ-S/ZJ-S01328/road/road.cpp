#include<bits/stdc++.h>
using namespace std;
const int nn=1e3+10;
struct node{
	int x,y,w;
}a[nn];
int fa[nn];
bool f[nn][nn];
int n,m,k,x,y,w,w1,ans,t;
void youhua(){
	ios::sync_with_stdio(0);
	cin.tie(0);
}
void init(){
	for(int i=1;i<=n;i++)
		fa[i]=i;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void join(int x,int y){
	int xx=find(x),yy=find(y);
	if(xx!=yy) fa[xx]=yy;
}
bool cmp(node x,node y){
	return x.w<y.w;
}
void kus(){
	int xx=0,yy=0;
	sort(a+1,a+t+1,cmp);
	for(int i=1;i<=t;i++)
	{
		xx=find(a[i].x);
		yy=find(a[i].y);
		if(xx!=yy)
		{
			ans=ans+a[i].w;
			join(x,y);
		} 
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	youhua();
	cin>>n>>m>>k;
	init();
	for(int i=1;i<=m;i++){
		cin>>x>>y>>w;
		a[++t].x=x;
		a[t].y=y;
		a[t].w=w;
		f[x][y]=true;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(!f[i][j]) 
				join(i,j);
	for(int i=1;i<=k;i++){
		cin>>w;
		for(int j=1;j<=m;j++){
			cin>>w1;
			a[++t].x=i+k;
			a[t].y=j;
			a[t].w=w+w1;
		}
	}
		
	cout<<ans;
}


