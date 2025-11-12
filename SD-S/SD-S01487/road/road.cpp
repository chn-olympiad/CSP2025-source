#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long

using namespace std;

const int N=1e4+10,M=1e6+10;

int n,m,k;

int f[N],c[N],a[20][N],mi[20],mind[20],u[M],v[M],w[M];

ll sum=0,ans=0x3f3f3f3f3f3f3f3f;

struct edge{
	int u,v,w;
}E[M+N*10];

bool cmp(edge x,edge y){
	return x.w<y.w;
}

int Find(int x){
	if(f[x]==x) return x;
	else return f[x]=Find(f[x]);
} 

void merge(int x,int y){
	int fx=Find(x),fy=Find(y);
	if(fx!=fy){
		f[fx]=fy;
	}
}

struct Node{
	int v,w;
};


int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n>>m>>k;
	
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	
	int flag=1;
	
	for(int i=1;i<=k;i++){
		cin>>c[i];
		mi[i]=0x3f3f3f3f;
		if(c[i]!=0) flag=0;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(mi[i]>a[i][j]){
				mi[i]=a[i][j];
				mind[i]=j;
			}
		}
		if(mi[i]!=0) flag=0;
	}
	
	if(flag){
		int uk=(1<<k)-1;
		for(int i=1;i<=m;i++){
			E[i]={u[i],v[i],w[i]};
		}
		int cnt=0,cnd=0;
		for(int i=1;i<=k;i++){
			if(uk&(1<<(i-1))){
				E[m+(++cnt)]={n+(++cnd),mind[i],mi[i]+c[i]};
				for(int j=1;j<=n;j++){
					if(j!=mind[i]){
						E[m+(++cnt)]={n+cnd,j,a[i][j]};
					}
				}
			}
		}
		
		sum=0;
		for(int i=1;i<=n+cnd;i++) f[i]=i;
		
		sort(E+1,E+1+m+cnt,cmp);
		
		for(int i=1;i<=m+cnt;i++){
			int u=E[i].u,v=E[i].v,w=E[i].w;
			int fu=Find(u);
			int fv=Find(v);
			if(fu!=fv){
				sum+=w;
				merge(fu,fv);
//				vt[u].push_back(v);
//				vt[v].push_back(u);
			}
		}
		ans=min(ans,sum);
		cout<<ans;
		return 0;
	}
	
	
	sum=0;
	
	for(int i=1;i<=m;i++){
		E[i]={u[i],v[i],w[i]};
	}
	
	for(int uk=0;uk<=(1<<k)-1;uk++){
//		int uk=4;
		sum=0;
		int cnt=0,cnd=0;
		
		for(int i=1;i<=m;i++){
			E[i]={u[i],v[i],w[i]};
		}
		
		for(int i=1;i<=k;i++){
			if(uk&(1<<(i-1))){
//				E[m+(++cnt)]={n+(++cnd),mind[i],mi[i]};
				sum+=c[i];
				cnd++;
				for(int j=1;j<=n;j++){
//					if(j!=mind[i]){
						E[m+(++cnt)]={n+cnd,j,a[i][j]};
//					}
				}
			}
		}
		
		for(int i=1;i<=n+cnd;i++) f[i]=i;
		
		sort(E+1,E+1+m+cnt,cmp);
		
		for(int i=1;i<=m+cnt;i++){
			int u=E[i].u,v=E[i].v,w=E[i].w;
			int fu=Find(u);
			int fv=Find(v);
			if(fu!=fv){
				sum+=w;
				merge(fu,fv);
//				vt[u].push_back(v);
//				vt[v].push_back(u);
			}
		}
//		if(ans>sum){
//			cout<<ans<<" "<<sum<<" "<<uk<<"\n";
//		}
		ans=min(ans,sum);
	}
	
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
