#include <bits/stdc++.h>
using namespace std;
const int maxm=2e6+10;
const int maxn=1e4+10;
int n,m,k,cnt,fa[maxn],ans,use;
//vector <pair<int,int>> a;
struct road{
	int u,v,w;
}p[maxm];
bool cmp(road x,road y){
	return x.w<y.w;
}
int findfather(int u){
	if(fa[u]==u) return u;
	return fa[u]=findfather(fa[u]);
}
void hb(int x,int y){
	x=findfather(x);
	y=findfather(y);
	fa[x]=y;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		for(int j=0;j<=k;j++){
			cnt++;
			p[cnt].u=u+j*n;
			p[cnt].v=v+j*n;
			p[cnt].w=w;
		}
	}
	cnt=n*(k+1);
	for(int i=1;i<=k;i++){
		int c,tp;
		cin >> c;
		for(int j=1;j<=n;j++){
			cin >> tp;
			for(int s=1;s<=n;s++){//s->j
				if(s==j) continue;
				cnt++;
//				cout << s+(i-1)*n << ' ' << j+i*n << ' ' << c+tp << '\n';
				p[cnt].u=s+(i-1)*n;
				p[cnt].v=j+i*n;
				p[cnt].w=c+tp;
			}
		}
	}
	sort(p+1,p+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		if(findfather(p[i].u)!=findfather(p[i].v)){
			use++;
//			cout << p[i].u << ' ' << p[i].v << ' ' << p[i].w << '\n';
			hb(p[i].u,p[i].v);
			ans+=p[i].w;
		}
		if(use==n-1) break;
	}
	cout << ans;
	return 0;
}
