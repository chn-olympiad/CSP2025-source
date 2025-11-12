#include <bits/stdc++.h>
using namespace std;

inline int read() {
	int x=0,ch=getchar();
	for(;!isdigit(ch);ch=getchar()) ;
	for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+(ch&15);
	return x;
}

using pii=pair<int,int>;
const int N=1e5+5,A=2e4+5;
int T,n,a[N][3],cnt[3];
priority_queue<int> pq[3];

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	for(T=read();T--;) {
		int ans=0;
		for(int i=(n=read(),1);i<=n;i++) {
			a[i][0]=read(),a[i][1]=read(),a[i][2]=read();
			int id[3]={0,1,2};
			sort(id,id+3,[&](int x,int y) {
				return a[i][x]>a[i][y];
			});
			if(pq[id[0]].size()>=(n>>1)) {
				int t=pq[id[0]].top();
				if(t>=a[i][id[1]]-a[i][id[0]]) {
					pq[id[0]].pop(),pq[id[0]].emplace(a[i][id[1]]-a[i][id[0]]);
					ans+=a[i][id[0]]+t;
				}
				else ans+=a[i][id[1]];
			}
			else pq[id[0]].emplace(a[i][id[1]]-a[i][id[0]]),ans+=a[i][id[0]];
		}
		while(!pq[0].empty()) pq[0].pop();
		while(!pq[1].empty()) pq[1].pop();
		while(!pq[2].empty()) pq[2].pop();
		printf("%d\n",ans);
	}
	return 0;
}

// 15:20
