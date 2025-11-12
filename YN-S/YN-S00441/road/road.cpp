#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll ans;
int n,m,k,a[1005][1005],x,y,dis,c[1005],b[1005],cnt[1005];
priority_queue<int> q;
int f(int x) {
	return max(1,n-cnt[x]-cnt[n-cnt[x]]+1);
}
bool check() {
	int scc[1005],res=cnt[1],uev[1005],ip[1005],t=1,vis[1005];
	for (int i=1; i<=n; i++)
		ip[i]=f(i),uev[i]=0x3f;
	for (int i=1; i<=n; i++) {
		if (a[ip[i]][i]!=0x3f) {
			uev[i]=min(uev[i]-a[ip[i]][0],0);
			if (!vis[t]) {
				scc[i]=a[ip[i]][i]+max(uev[i],c[t]+b[ip[i]]+b[i]);
				uev[i]-=uev[f(ip[i])];
				cnt[i]--,cnt[ip[i]]--;
				vis[t]=1;
			}
			ip[i]=f(ip[i]);
			t=f(t);
		} else
			scc[i]=-1;
	}
	for (int i=1; i<=n; i++)
		if (scc[i]!=-1)
			res-=f(i);
	return res>=0;
}
void bfs(int x) {
	while (!q.empty())
		q.pop();
	for (int i=1; i<=n; i++)
		if (i!=x&&a[x][i]!=0x3f)
			q.push(a[x][i]);
	while (check())
		ans-=q.top(),q.pop();
}
int lc(int x) {
	while (!q.empty())
		q.pop();
	for (int i=1; i<=n; i++)
		if (x!=i)
			q.push(a[x][i]-a[x][f(x)]);
	return q.top();
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	memset(a,0x3f,sizeof(a));
	for (int i=1; i<=m; i++) {
		scanf("%d%d%d",&x,&y,&dis);
		ans+=dis;
		cnt[x]++,cnt[y]++;
		a[x][y]=a[y][x]=dis;
	}
	for (int i=1; i<=k; i++) {
		scanf("%d",&c[i]);
		for (int j=1; j<=n; j++)
			scanf("%d",&b[j]);
		for (int j=1; j<=n; j++)
			for (int k=1; k<=n; k++)
				a[k][j]=a[j][k]=min(a[j][k],b[j]+b[k]);
	}
	for (int i=1; i<=n; i++)
		bfs(i);
	for (int i=1; i<=n; i++)
		ans+=f(lc(i));
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}