#include<iostream>
#include<algorithm>
#define MAXN 1000005
using namespace std;

int n,m,k;
int u,v,w;
int c[15];
int a[15][10005];
int ans=0;

struct lu{
	int u;
	int v;
	int w;
	bool used;
};
lu r[MAXN];

bool cmp(lu x,lu y){
	return x.w<y.w;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.out","r",stdin);
	freopen("road.out","w",stdout); 
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>r[i].u>>r[i].v>>r[i].w;
		r[i].used=0;
		ans+=r[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	
	sort(r+1,r+m+1,cmp);
	r[1].used=1;
	ans+=r[1].w;
	cout<<ans/2;
	return 0;
}
