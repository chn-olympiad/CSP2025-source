#include<bits/stdc++.h>
using namespace std;
bool vis[100006];
priority_queue<pair<int,pair<int,int> > > q;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while (t--) {
		memset(vis,0,sizeof(vis));
		int n,nn[3]= {0,0,0},nnn,res=0;
		scanf("%d",&n);
		for (int i=0,a1,a2,a3; i<n; i++) {
			scanf("%d%d%d",&a1,&a2,&a3);
			q.push({a1,{i,0}});
			q.push({a2,{i,1}});
			q.push({a3,{i,2}});
		}
		nnn=n;
		while (nnn) {
			pair<int,pair<int,int> > tp=q.top();
			q.pop();
			if (nn[tp.second.second]<n/2&&!vis[tp.second.first]) {
				nn[tp.second.second]++;
				vis[tp.second.first]=1;
				res+=tp.first;
				nnn--;
			}
		}
		printf("%d\n",res);
		while (q.size()) q.pop();
	}
	return 0;
}

