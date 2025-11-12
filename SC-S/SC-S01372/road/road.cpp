#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;

int n,m,k;

long long price;
struct node{
	long long u,v,w;
};
vector<node>vec;
vector<long long >a;

int fa[N];

int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}

bool cmp(node a,node b){
	return a.w<b.w;
}

long long ans;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

//	freopen("road2.in","r",stdin);

//	cin>>n>>m>>k;
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)fa[i]=i;
	while(m--){
		node lin;
//		cin>>lin.u>>lin.v>>lin.w;
		scanf("%lld%lld%lld",&lin.u,&lin.v,&lin.w);
		vec.push_back(lin);
	}
	while(k--){
		a.erase(a.begin(),a.end());
//		cin>>price;
		scanf("%lld",&price);
		long long lin;
		for(int i=1;i<=n;i++){
//			cin>>lin;
			scanf("%lld",&lin);
			a.push_back(lin);
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				vec.push_back(node{i+1,j+1,price+a[i]+a[j]});
			}
		}
	}
	
	sort(vec.begin(),vec.end(),cmp);
	for(int i=0;i<vec.size();i++){
		node it = vec[i];
		int x=find(it.u);
		int y=find(it.v);
		if(x!=y){
			fa[x]=y;
			ans+=it.w;
		}
	}
//	cout<<ans;
	printf("%lld",ans);
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