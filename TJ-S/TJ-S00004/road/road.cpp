#include <bits/stdc++.h>
using namespace std;
int n,k,m;
bool zhan[15];
long long c[15];
long long a[15][10005];
long long e[10005][10005];
bool p[10005];
long long ans=1e9,ans1=0;
vector<long long> s[10005];
struct k{
	long long u,v;
}b[1000005];
void dfs(int t) {
	bool o=0;
	for (int i=1;i<=n;i++) {
		if (p[i]==0) {
			o=1;
			break;
		}
	}
	if (o==0) ans=min(ans,ans1);
	else {
		for (auto i:s[t]) {
			int r=0;
			for (int j=1;j<=k;j++) {
				if (zhan[j]==1) {
					e[t][i]=min(e[t][i],a[j][i]+a[j][t]);
					if (e[t][i]==a[j][i]+a[j][t]) {
						r=0;
					}
				}
				else {
					e[t][i]=min(e[t][i],c[j]+a[j][i]+a[j][t]);
					if (e[t][i]==c[j]+a[j][i]+a[j][t]) {
						r=j;
					}
				}
			}
			//cout << e[t][i] << " ";
			dfs(t+1);
			//cout << ans1 << " ";
			if (r!=0) {
				zhan[r]=1;
			}
			int zx=p[t],zy=p[i];
			p[t]=p[i]=1;
			ans1+=e[t][i];
			dfs(t+1);
			//cout << ans1 << "  ";
			p[t]=zx;
			p[i]=zy;
			ans1-=e[t][i];
		}
	}
}
int main() {
	freopen("road","r",stdin);
	freopen("road","w",stdout);
	bool f=0,fla=0;
	cin >> n >> m >> k;
	for (int i=1;i<=m;i++) {
		cin >>b[i].u>>b[i].v;
		long long re=b[i].u,rs=b[i].v;
		cin >> e[re][rs];
		s[b[i].u].push_back(b[i].v);
		s[b[i].v].push_back(b[i].u);
	}
	for (int i=1;i<=k;i++) {
		f=0;
		cin >>c[i];
		if (c[i]!=0) f=1;
		for (int j=1;j<=m;j++) {
			cin >>a[i][j];
			if (a[i][j]!=0) f=1;
		}
		if (f==0) fla=1;
	}
	if (fla==1) {
		cout << f-1;
	}
	else {
		dfs(1);
		cout << ans;
	}
	return 0;
}
