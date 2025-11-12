#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int N=1e4+20;
int c[N];
bool vis[N],f[N];
struct node {
	int i,j,w;
} s[N];
bool cmp(node x,node y) {
	return x.w<y.w;
}
vector<int> ti[N],tj[N],tw[N];
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,cnt=1;
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		int x,y,z;
		cin>>x>>y>>z;
		s[cnt].i=x;
		s[cnt].j=y;
		s[cnt].w=z;
		cnt++;
	}
	for(int i=1; i<=k; i++) {
		cin>>c[i];
		for(int j=1; j<=n; j++) {
			int x;
			cin>>x;
			s[cnt].i=j;
			s[cnt].j=n+i;
			s[cnt].w=x+c[i];
			cnt++;
			s[cnt].i=j;
			s[cnt].j=-i;
			s[cnt].w=x;
			cnt++;
		}
	}
	sort(s+1,s+cnt,cmp);
	int i=1;
	int rcnt=0,ans=0;
	while(rcnt<n&&i<cnt) {
		if(s[i].j>0&&s[i].j<=n&&(f[s[i].i]==0||f[s[i].j]==0)) {
			ans+=s[i].w;
			if(f[s[i].i]==0)rcnt++;
			if(f[s[i].j]==0)rcnt++;
			f[s[i].i]=1;
			f[s[i].j]=1;
		} else if(s[i].j>n&&vis[s[i].j-n]==0&&f[s[i].i]==0) {
			ans+=s[i].w;
			vis[s[i].j-n]=1;
			f[s[i].i]=1;
			rcnt++;
			for(int j=0; j<ti[s[i].j-n].size(); j++) {
				if(f[ti[s[i].j-n][j]]==0) {
					ans+=tw[s[i].j][j];
					f[ti[s[i].j][j]]=1;
					rcnt++;
				}
			}
		} else if(s[i].j<0) {
			if(vis[-s[i].j]==1&&f[s[i].i]==0) {
				ans+=s[i].w;
				f[s[i].i]=1;
				rcnt++;
			} else if(vis[-s[i].j]==0) {
				ti[-s[i].j].push_back(s[i].i);
				tw[-s[i].j].push_back(s[i].w);
			}
		}
		i++;
	}
	cout<<ans;
	return 0;
}
