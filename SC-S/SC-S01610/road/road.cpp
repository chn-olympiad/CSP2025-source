#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+5,M=1e6+5;
int n,m,k,e[15],Min=1e18,fa[N];
struct node{int u,v,w;};
vector<node> g,v[15],t;
bool cmp(node x,node y){return x.w<y.w;}
int ff(int x){
	if(x==fa[x])return x;
	else return ff(fa[x]); 
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,x,y,w;i<=m;i++){
		cin>>x>>y>>w;
		g.push_back({x,y,w});
	}
	for(int i=1;i<=k;i++){
		cin>>e[i];
		for(int j=1,w;j<=n;j++){
			cin>>w;v[i].push_back({i+n,j,w});
		}
	}
	for(int s=0;s<(1<<k);s++){
		int ct=n-1,sum=0,len=0;
		t.clear();
		for(node p:g)t.push_back(p);
		for(int i=1;i<=k;i++)
			if((1<<(i-1))&s){
				for(node p:v[i])
					t.push_back(p);
				ct++;sum+=e[i];
			}
		sort(t.begin(),t.end(),cmp);
		for(int i=1;i<=n+k;i++)fa[i]=i;
		for(node i:t){
			if(ff(i.u)!=ff(i.v)){
				fa[ff(i.u)]=ff(i.v);
				sum+=i.w;len++;
			}
			if(len==ct)break;
		}
		Min=min(Min,sum);
	}
	cout<<Min;
} 