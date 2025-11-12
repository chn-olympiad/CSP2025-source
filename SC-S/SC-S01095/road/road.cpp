#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5,M=1e6+5;

struct node{
	int u,v,w,i;
}a[M+10*N];
int cnt;

bool cmp(node x,node y){
	return x.w<y.w;
}

int n,m,k;
int b[N],c[15][N],ans;
int t[15],tt[15];

int fa[N];

int getfa(int x){
	if(fa[x]==x)
		return x;
	return fa[x]=getfa(fa[x]);	
}



void kk(){
	int o=n;
	for(int i=1;i<=cnt;i++){
		int xx=getfa(a[i].u);
		int yy=getfa(a[i].v);
		if(xx>yy)swap(xx,yy);
		if(xx!=yy){
			fa[yy]=xx;
			ans+=a[i].w;
			if(a[i].i!=0){
				if(t[a[i].i]>=1){
					ans-=b[a[i].i];
					t[a[i].i]++;
					tt[a[i].i]=0;
				}
				if(t[a[i].i]==0){
					t[a[i].i]=1;
					tt[a[i].i]=a[i].w;
				}				
			}

		}

	}
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[i].u=u,a[i].v=v,a[i].w=w,a[i].i=0;
	}
	cnt=m;
	for(int i=1;i<=k;i++){
		cin>>b[i];
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
		}
	}
	
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			a[++cnt].w=c[i][j]+b[i];
			a[cnt].u=i+n,a[cnt].v=j;
			a[cnt].i=i;
		}
	}
	
	sort(a+1,a+1+cnt,cmp);

	//输入 
	//最小生成树
	for(int i=1;i<=n+k;i++)
		fa[i]=i;
	kk();
	for(int i=1;i<=k;i++){
		ans-=tt[i];
		//cout<<tt[i]<<" ";
	}
	cout<<ans;
	
	return 0;
}
