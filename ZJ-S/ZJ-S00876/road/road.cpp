#include<bits/stdc++.h>
#define LL long long

using namespace std;

const int N=1e6+10;
int n,m,k;
LL ans;
LL res=LLONG_MAX;

struct Node{
	int u,v,w;
}a[10*N];
int b[N];
int c[15][N];
int idx;
int cnt;

int fa[10*N];
void init(){
	for(int i=1;i<=m+k*n;i++){
		fa[i]=i;
	}
}

int find(int x){
	return (fa[x]==x?x:fa[x]=find(fa[x]));
}

void merge(int x,int y){
	x=find(x);
	y=find(y);
	if(x!=y){
		fa[x]=y;
	}
}

void kruskal(){
	for(int i=1;i<=m+idx;i++){
		if(find(a[i].u)!=find(a[i].v)){
			merge(a[i].u,a[i].v);
			ans+=a[i].w;
		}
//		cout<<a[i].u<<" "<<a[i].v<<"\n";
	}
}

bool cmp(Node A,Node B){
	return A.w<B.w;	
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	
	for(int i=1;i<=k;i++){
		cin>>b[i];
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
		}
	}
	
	if(k==0){
		init();
		sort(a+1,a+m+1,cmp);
		kruskal();
		cout<<ans<<"\n";
		return 0;
	}
	
	init();
	sort(a+1,a+m+1,cmp);
	kruskal();
	res=min(res,ans);
	ans=0;
	
	for(int i=1;i<=1;i++){
		for(int j=i;j<=1;j++){
			idx=m;
			cnt=m;
			for(int l=i;l<=j;l++){
				a[++idx].u=++cnt;
				a[idx].v=1;
				a[idx].w=c[l][1];
				for(int r=2;r<=n;r++){
					a[++idx].u=cnt;
					a[idx].v=r;
					a[idx].w=c[l][r];
				}
				ans+=b[l];
			}
			sort(a+1,a+m+(j-i+1)*n+1,cmp);
			init();
			kruskal();
			res=min(res,ans);
			ans=0;
			
//			if(i==j&&i==1){
//				for(int i=1;i<=m+idx;i++){
//					cout<<a[i].u<<" "<<a[i].v<<" "<<a[i].w<<"\n";
//				}
//			}
		}
	}
	
	cout<<res<<"\n";
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
