#include<bits/stdc++.h>
#define debug 0
using namespace std;

//struct city{
//	vector<pair<int,int>> to;
//}mp[10010];
struct edge {
	int u,v,w;
	bool operator<(const edge &aa) {
		return w<aa.w;
	}
} e[1000010];

int n,m,k,c[11],a[11][10010];

int fa[10010];
void init() {
	for(int i=1; i<=n; i++) {
		fa[i]=i;
	}
}
int getfa(int n) {
	if(fa[n]==n) {
		return n;
	}
	fa[n]=getfa(fa[n]);
	return fa[n];
}

void unio(int a,int b) {
	
	fa[getfa(a)]=getfa(b);
}

int cnt=0;

int main() {
	cin.tie(0);

	if(!debug) {
		freopen("road.in","r",stdin);
		freopen("road.out","w",stdout);
	}

	cin>>n>>m>>k;

	for(int i=1; i<=m; i++) {
		int u,v,w;
		cin>>u>>v>>w;
		cnt++;
		e[cnt].u=u;
		e[cnt].v=v;
		e[cnt].w=w;
	}

	int sp1=1;

	for(int i=1; i<=k; i++) {
		cin>>c[i];
		if(c[i]) {
			sp1=0;
		}
		for(int j=1; j<=n; j++) {
			cin>>a[i][j];
		}
	}

	if(sp1) {

		for(int i=1; i<=k; i++) {
			for(int j=1; j<=n; j++) {
				if(a[i][j]!=0) {
					continue;
				}
				int u=j;
				for(int aa=1; aa<=n; aa++) {
					if(aa==j) {
						continue;
					}
					cnt++;
					e[cnt].u=u;
					e[cnt].v=aa;
					e[cnt].w=a[i][aa];
					if(debug){
						cout<<"unioned: "<<u<<' '<<aa<<' '<<a[i][aa]<<"\n"; 
					}
				}
				break;

			}
		}

		init();

		sort(e+1,e+cnt+1);

		int ans=0;

		for(int i=1; i<=cnt; i++) {
			if(getfa(e[i].u)!=getfa(e[i].v)) {

				if(debug) {
					cout<<"connected: "<<e[i].u<<' '<<e[i].v<<"\n";
					cout<<getfa(e[i].u)<<' '<<getfa(e[i].v)<<"\n";
				}
				ans+=e[i].w;
				unio(e[i].u,e[i].v);
			}

		}
		cout<<ans;

		return 0;
	}

	return 0;
}

//ccf //freopen luogu 114514 rp++ 
