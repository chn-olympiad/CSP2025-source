#include<bits/stdc++.h>
#define endl '\n' 
#define ll long long
const int M=1e6+1e5+5,N=1e4+5;
int n,m,k;
using namespace std;
struct node{
	int x,y;ll w;
}edge[M];
ll chh[N][N]; 
int a[N]={0};
int fa[N]={0};
int father(int x){
	if(fa[x]!=x)fa[x]=father(fa[x]);
	return fa[x];
}
bool unionn(int x,int y){
	int f1=father(x);
	int f2=father(y);
	if(f1!=f2){
		fa[f1]=f2;
		return 1;
	}
	return 0;
}
bool cmp(node x,node y){
	return x.w<y.w;
}
ll rmn[N][N];
ll ans=0;
ll mx=-0x3f3f3f3f;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	memset(rmn,0x3f,sizeof(rmn));
	for(int i=1;i<=m;i++){
		cin>>edge[i].x>>edge[i].y>>edge[i].w;
		rmn[edge[i].x][edge[i].y]=min(rmn[edge[i].x][edge[i].y],edge[i].w);
		rmn[edge[i].y][edge[i].x]=min(rmn[edge[i].x][edge[i].y],edge[i].w);
		mx=max(mx,edge[i].w);
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		for(int r=1;r<=n;r++){
			cin>>a[r];
			for(int l=1;l<r;l++){
				chh[l][r]=a[r]+a[l]+c;
				chh[r][l]=a[l]+a[r]+c;
				if(a[r]+a[l]+c<rmn[l][r]){
					edge[++m].x=l;edge[m].y=r;edge[m].w=a[r]+a[l]+c;
				}
			} 
		}
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		edge[i].w=min(edge[i].w,chh[edge[i].x][edge[i].y]);
	} 
	sort(edge+1,edge+1+m,cmp);
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(unionn(edge[i].x,edge[i].y)){
			cnt++;
			ans+=edge[i].w;
		} 
		if(cnt==n-1)break;
	}
	cout<<ans;
	return 0;
} 

