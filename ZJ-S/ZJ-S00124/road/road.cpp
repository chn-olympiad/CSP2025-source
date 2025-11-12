#include<bits/stdc++.h>
using namespace std;
const int M=1e4;
struct edge{
	int v;long long w;
	bool operator<(const edge&b)const{
		return w>b.w;}
};priority_queue<edge>q;
int b[15];bool v[10015];
vector<edge>a[10015];
long long d[10015];
void dij(){
	q.push({1,0});v[1]=1,d[1]=0;
	while(q.size()){
		edge p=q.top();q.pop();
		for(edge&i:a[p.v]){
			if(!v[i.v]){
				d[i.v]=p.w+i.w;
				if(i.v>M&&!v[i.v]) i.w-=b[i.v-M];
				v[i.v]=1;q.push({i.v,d[i.v]});}
		}
	}
}int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n,m,k,x,y,z;cin>>n>>m>>k;long long s=0;
	while(m--){
		cin>>x>>y>>z,s+=z;
		a[x].emplace_back(edge{y,z});
		a[y].emplace_back(edge{x,z});
	}if(!k){cout<<s;return 0;}
	for(int i=1;i<=k;i++){
		cin>>b[i];
		for(int j=1;j<=n;j++){
			cin>>x;
			a[M+i].emplace_back(edge{j,x+b[i]});
			a[j].emplace_back(edge{M+i,x+b[i]});
		}
	}memset(d,0x7f,sizeof d);
	dij();cout<<*max_element(d+1,d+n+1);
	return 0;
}
