#include<bits/stdc++.h>
using namespace std;
struct point{
	int x,y;
	bool operator > (const point& a) const{
		return x>a.x;
	}
}tmp;
int m,n,k;
vector<point > a[10010];
priority_queue<point,vector<point>,greater<point> > q;
int dis[10010],xc[15][10010],fy[15];
bool ff[10010],f[12],d[12][10010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		a[x].push_back({y,z});
		a[y].push_back({x,z});
	}
	for(int i=1;i<=k;i++){
		cin>>fy[i];
		for(int j=1;j<=n;j++){
			cin>>xc[i][j];
		}
	}
	dis[1]=0;
	for(int i=2;i<=n;i++){
		dis[i]=INT_MAX;
		
	}
	tmp.x=1;
	tmp.y=0;
	q.push(tmp);
	int ans=0,sum=0;
	while(!q.empty()){
		tmp=q.top();
		int u=tmp.x;
		q.pop();
		if(ff[u]){
			continue;
		}
		
		ff[u]=1;
			sum+=tmp.y;
		ans++;
		for(int i=0;i<a[u].size();i++){
			if(dis[a[u][i].x]>a[u][i].y){
				dis[a[u][i].x]=a[u][i].y;
				tmp.x=a[u][i].x;
				tmp.y=a[u][i].y;
				q.push(tmp);
			}
		}
	}
	cout<<sum;
	return 0;
}//RP++

/*4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
