#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
typedef pair<ll,int> PII;
const int N=2e6+10;
int e[N],ne[N],h[N],idx;
ll d[N];
ll w[N];
bool st[N];
void add(int a,int b,int c){
	e[++idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx;
}
void dijk(){
	memset(d,0x3f,sizeof d);
	d[1]=0;
	priority_queue<PII,vector<PII>,greater<PII> > q;
	q.push({0,1});
	while(!q.empty()){
		PII t=q.top();
		q.pop();
		int v=t.second;
		if(st[v]) continue;
		st[v]=1;
		for(int i=h[v];i;i=ne[i]){
			int j=e[i];
			if(d[j]>d[v]+w[i]){
				d[j]=d[v]+w[i];
				q.push({d[j],j});
			}
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0)->sync_with_stdio(0);
	int n,m,k;
	cin>>n>>m>>k;
	while(m--){
		int a,b;
		ll c;
		cin>>a>>b>>c;
		add(a,b,c);
		add(b,a,c);
	}
	dijk();
	cout<<d[n];
	return 0;
}

