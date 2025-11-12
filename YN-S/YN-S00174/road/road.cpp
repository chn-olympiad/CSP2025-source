#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
const int M = 1e6 + 10;
int pa[N]={0};
struct edge{
	int f,t,w;
};
vector<edge>cnm;
int find(int x){
	if(pa[x]==x) return x;
	else return pa[x]=find(pa[x]);
}
bool cmp(edge t,edge y){
	return t.w<y.w;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n,m,k;
	cin>>n>>m>>k;
	if(k==0){
		for(int i=0;i<n;i++){
			pa[i]=i;
		}
		for(int i=0;i<m;i++){
			int x,y,z;
			cin>>x>>y>>z;
			cnm.push_back({x,y,z});
			if(pa[x]!=pa[y])
				pa[find(x)]=pa[find(y)];
		}
		long long int ans=0;
		sort(cnm.begin(),cnm.end(),cmp);
		for(int i=0;i<m;i++){
			if(pa[cnm[i].f]!=pa[cnm[i].t]){
				ans+=cnm[i].w;
			}
		}
		cout<<ans<<endl;
	}else{
		cout<<"0"<<endl;
	}
	return 0;
}
