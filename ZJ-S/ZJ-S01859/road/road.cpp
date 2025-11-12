#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define VE vector
#define PQ priority_queue
struct f{LL u,v,a;};struct w{LL v,p;};

LL n,m,ans,k,u,v,a,r,q0;VE<f>gr;unordered_map<LL,VE<w>>xc;PQ<LL,VE<LL>,greater<LL>>q;VE<LL>e;
unordered_set<LL> vi;
LL cmp(f a,f b){return a.a<b.a;}
LL cmp2(w a,w b){return a.v<b.v;}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;gr.resize(n);e.resize(k+1,0);
	for(LL i=0;i<m;i++){
		cin>>gr[i].u>>gr[i].v>>gr[i].a;
	}
	for(LL i=0;i<k;i++){
		cin>>a;q.push(a);e[i+1]=a;for(LL i=0;i<n;i++){
			cin>>u;if(u!=0){
				q0=1;
			}xc[i].push_back({u,i});
		}
		sort(xc[i].begin(),xc[i].end(),cmp2);
	}
	sort(gr.begin(),gr.end(),cmp);q.push(0);
		/*for(auto [uu,vv,aa]:gr){
		cout<<uu<<" "<<vv<<" "<<aa;
	}*/
	if(!q0&&k!=0){cout<<0;
		return 0;
	}
	//cout<<1;
	for(auto [uu,vv,aa]:gr){
		ans+=aa;r++;//cout<<ans<<r;
		if(r==n){
			break;
		}
	}
	cout<<ans;
	return 0;
}
