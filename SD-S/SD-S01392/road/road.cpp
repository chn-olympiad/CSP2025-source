#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,ans;
struct Line{
	int u,v,d;
	bool operator > (const Line &x)const{
		return d > x.d;
	}
};
//vector<L>e[100005];
bitset<100015>b;
int dfirst[15];
bool bb[15];
int c[15],a[15][100005];
priority_queue<Line,vector<Line>,greater<Line> >q;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1;i<=m;i++){
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		q.push(Line{y,x,w});
		q.push(Line{x,y,w});
	}
	for(int i = 1;i<=k;i++){
		scanf("%d",&c[i]),ans += c[i];
		for(int j = 1;j<=n;j++)scanf("%d",&a[i][j]),q.push(Line{j,n + i,a[i][j]}),q.push(Line{n + i,j,a[i][j]});
	}
		int pp = 0; 
		b.reset();
		while(pp < n + k - 1){
			while(b[q.top().v] && b[q.top().u])q.pop();
			int rp = q.top().u,p = q.top().v,dist = q.top().d;
			cout << rp << " " << p << " " << dist << " " << ans << "\n";
//			if(rp > n)dfirst[rp - n] ? bb[rp - n] = 1 : dfirst[rp - n] = dist;
//			if(p > n)dfirst[p - n] ? bb[p - n] = 1 : dfirst[p - n] = dist;
//			cout << p << " " << dist << "\n";
			q.pop();
			ans += dist;
			b.set(rp),b.set(p);
			pp++;
		}
//	for(int i = 1;i<=k;i++)ans -= bb[i] * (c[i] + dfirst[i]);
	printf("%d",ans);
	return 0;
}//Ren5Jie4Di4Ling5%


