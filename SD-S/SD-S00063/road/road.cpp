#include<bits/stdc++.h>
using namespace std;
long long n,m,k,l,r,d,ccd,lef,aband;
int fa[(int)1e4+63];
//bool fathe[(int)1e4+63];
struct edge{
	int from;
	int to;
	long long dis;
	int fromzhen;
	bool operator<(const edge &TI)const{
		return dis<TI.dis;
	}
};
vector<edge> ve;
long long to[(int)1e3+33][11];
int buil[11];
bool used[11];
int findfa(int x){
	if(x==fa[x]) return x;
	fa[x]=findfa(fa[x]);
	return fa[x];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	cin>>n>>m>>k;
	lef=n;
	for(int i=1;i<=n;i++){
		//fathe[i]=1;
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>l>>r>>d;
		ve.push_back({l,r,d,0});
	}
	for(int i=1;i<=k;i++){
		cin>>ccd;
		buil[i]=ccd;
		for(int j=1;j<=n;j++){
			cin>>to[j][i];
			to[j][i]+=ccd;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			long long minss=LLONG_MAX;
			int rrr;//minss=min(minss,to[i][ks]+to[j][ks]-buil[ks]);
			for(int ks=1;ks<=k;ks++){
				if(minss>to[i][ks]+to[j][ks]-buil[ks]){
					rrr=ks;
					minss=min(minss,to[i][ks]+to[j][ks]-buil[ks]);
				}
			}
			ve.push_back({i,j,minss,rrr});
		}
	}
	int pos=0;
	sort(ve.begin(),ve.end());
	while(lef!=1 || pos!=ve.size()){
		edge rt=ve[pos];
		pos++;
		if(findfa(rt.from)==findfa(rt.to)) continue;
		lef--;
		if(used[rt.fromzhen]) aband-=buil[rt.fromzhen];
		else used[rt.fromzhen]=1;
		fa[findfa(rt.from)]=findfa(rt.to);
		aband+=rt.dis;
	}
	cout<<aband;
}
