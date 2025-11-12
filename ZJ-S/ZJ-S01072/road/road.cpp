#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct str {
	int sum,x,y;
};
vector<str> lp;
int fa[10005];
int find(int a) {
	if(fa[a]==0) {
		return a;
	}
	return find(fa[a]);
}
bool same(int a,int b) {
	return find(a)==find(b);
}
bool cmp(str a,str b) {
	return a.sum<b.sum;
}
int n,m,k,edge[1005][1005],nk[12][10005];
ll sum;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0) {
		for(int i = 0; i<m; i++) {
			int x,y,l;
			scanf("%d%d%d",&x,&y,&l);
			lp.push_back({l,x,y});
		}
		int p = 0;
		sort(lp.begin(),lp.end(),cmp);
		int lll = 0;
		for(int i = 0; i<m; i++) {
			if(lll==n-1) break;
			int ml = lp[i].sum,x = lp[i].x,y = lp[i].y;
			if(!same(x,y)) {
				sum+=ml;
				fa[find(x)] = find(y);
				lll++;
			}
		}
		cout<<sum;
	} else {
		for(int i = 0; i<=n+1; i++) {
			for(int j = 0; j<=n+1; j++) {
				edge[i][j] = -1;
			}
		}
		for(int i = 0; i<m; i++) {
			int x,y,l;
			scanf("%d%d%d",&x,&y,&l);
			edge[x][y] = l;
			edge[y][x] = l;
		}
		for(int i = 1; i<=k; i++) {
			int l;
			cin>>l;
			for(int j = 1; j<=n; j++) {
				scanf("%d",&nk[i][j]);
			}
		}
		for(int i = 1; i<=n; i++) {
			for(int j = i+1; j<=n; j++) {
				for(int l = 1; l<=k; l++) {
					if(edge[i][j]==-1) {
						m++;
						edge[i][j] = nk[l][i]+nk[l][j];
						edge[j][i] = edge[i][j];
					} else {
						edge[i][j] = min(edge[i][j],nk[l][i]+nk[l][j]);
						edge[j][i] = edge[i][j];
					}
				}
			}
		}
		for(int i = 1; i<=n; i++) {
			for(int j = i+1; j<=n; j++) {
				if(edge[i][j]!=-1) {
					lp.push_back({edge[i][j],i,j});
				}
			}
		}
		int p = 0;
		sort(lp.begin(),lp.end(),cmp);
		int lll = 0;
		for(int i = 0; i<m; i++) {
			if(lll==n-1) break;
			int ml = lp[i].sum,x = lp[i].x,y = lp[i].y;
			if(!same(x,y)) {
				sum+=ml;
				fa[find(x)] = find(y);
				lll++;
			}
		}
		cout<<sum;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

