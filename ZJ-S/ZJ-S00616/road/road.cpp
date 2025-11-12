#include<bits/stdc++.h>
using namespace std;
struct a{
	long long v,w;
	bool operator <(const a &x) const{
		return w>x.w;
	}
};
vector<a>q[20010];
bool vi[10010];
priority_queue<a>p;
long long u[1000010],v[1000010],w[1000010];
int x[100010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	if(k==0){
		for(int c=0;c<m;c++){
			cin>>u[c]>>v[c]>>w[c];
			q[u[c]].push_back({v[c],w[c]});
			q[v[c]].push_back({u[c],w[c]});
		}
		vi[1]=1;
		int s=q[1].size();
		for(int c=0;c<s;c++){
			p.push({q[1][c].v,q[1][c].w});
		}
		int i=0;
		long long l=0;
		while(i<n){
			a pp=p.top();
			p.pop();
			if(vi[pp.v]){
				continue;
			}
			i++;
			l+=pp.w;
			int s=q[pp.v].size();
			for(int c=0;c<s;c++){
				p.push({q[pp.v][c].v,q[pp.v][c].w});
			}
		}
		cout<<l;
	}
	else{
		for(int c=0;c<m;c++){
			cin>>u[c]>>v[c]>>w[c];
			q[u[c]].push_back({v[c],w[c]});
			q[v[c]].push_back({u[c],w[c]});
		}
		for(int c=1;c<=k;c++){
			int o;
			cin>>o;
			for(int d=1;d<=n;d++){
				cin>>x[d];
				q[d].push_back({n+d,x[d]});
				q[n+d].push_back({d,x[d]});
			}
		}
		vi[1]=1;
		int s=q[1].size();
		for(int c=0;c<s;c++){
			p.push({q[1][c].v,q[1][c].w});
		}
		int i=1;
		long long l=0;
		while(i<n){
			a pp=p.top();
			p.pop();
			if(pp.v<=n){
				if(vi[pp.v]){
					continue;
				}
				vi[pp.v]=1;
				i++;
			}
			l+=pp.w;
			int s=q[pp.v].size();
			for(int c=0;c<s;c++){
				p.push({q[pp.v][c].v,q[pp.v][c].w});
			}
		}
		cout<<l;
	}
	return 0;
}