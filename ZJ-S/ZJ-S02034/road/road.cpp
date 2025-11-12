#include<bits/stdc++.h>
using namespace std;
const int N=1e4+51;
int n,m,k,fa[N],c[11],a[11][10001],p[11][10001],len;
bool f[N],f2[11];
struct node{
	int x;
	int y;
	int w;
	int p;
}v[2500001];
bool cmp(node x,node y){
	if(x.w<y.w){
		return true;
	}
	else{
		return false;
	}
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void bing(int x,int y){
	fa[y]=x;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x,y,w;
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>x>>y>>w;
		v[i].x=x;
		v[i].y=y;
		v[i].w=w;
		v[i].p=0;
	}
	len=m;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				v[++len]={j,k,a[i][j]+a[i][k]+c[i],i};
			}
		}
	}
	int ans=0,s=0;
	sort(v+1,v+len+1,cmp);
	for(int i=1;i<=len;i++){
		x=find(v[i].x),y=find(v[i].y);
		if(x==y) continue;
		if(v[i].p!=0){
			f2[v[i].p]=1;
			ans=0;
			s=0;
			for(int j=1;j<=n+k;j++){
				fa[j]=j;
				f[j]=0;
			}
			for(int j=1;j<=len;j++){
				if(v[i].p==v[j].p){
					v[j].w-=c[v[i].p];
					v[j].p=0;
				}
			}
			v[i].p=0;
			i=0;
			sort(v+1,v+len+1,cmp);
			continue;
		}
		ans+=v[i].w;
		bing(x,y);
		if(v[i].x<=n&&!f[v[i].x]){
			f[v[i].x]=1;
			s++;
		}
		if(v[i].y<=n&&!f[v[i].y]){
			f[v[i].y]=1;
			s++;
		}
		if(s>=n) break;
	}
	for(int i=1;i<=k;i++){
		if(f2[i]){
			ans+=c[i];
		}
	}
	cout<<ans;
	return 0;
}
