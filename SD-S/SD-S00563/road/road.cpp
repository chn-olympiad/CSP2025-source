#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct Edge{
	int x,y,w;
};
const int N = 1e4+5;
int n,m,k;
vector<pair<int,int> >t[N];//w,v
int c[N];
int a[11][N];

ll ans;
int b[N];
vector<Edge> e;

bool cmp(Edge x, Edge y){
	return x.w<y.w;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		t[u].push_back({v,w});
		t[v].push_back({u,w});
		e.push_back({u,v,w});
	}
	for(int j=1;j<=k;j++){
		for(int i=1;i<=n;i++){
			scanf("%d",&c[j]);
			scanf("%d",&a[j][i]);
		}
	}
	if(k==0){
		sort(e.begin(),e.end(),cmp);
		int cnt=0;
		for(auto i:e){
			if(!b[i.x]||!b[i.y]){
				b[i.x]=1;
				b[i.y]=1;
				ans+=i.w;
			}
		}
		printf("%d",ans);
		return 0;
	}
	
	
	return 0;
} 
