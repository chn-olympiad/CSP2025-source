#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
const int inf=0x3f3f3f3f,INF=0x3f3f3f3f3f3f3f3f;
using namespace std;
int a[100005][3],id[100005][3],cnt[3];
priority_queue<int>q;
vector<PII>tmp;
bool cmp(PII x,PII y){
	return a[x.first][x.second]>a[y.first][y.second];
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;scanf("%lld",&t);
	while(t--){
		int n,ans=0,cl=-1;scanf("%lld",&n);
		for(int i=1;i<=n;++i){
			scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);
			tmp.push_back({i,0}),tmp.push_back({i,1}),tmp.push_back({i,2});
			sort(tmp.begin(),tmp.end(),cmp);
			for(int c=0;c<3;++c)id[i][c]=tmp[c].second;
			tmp.clear();
			++cnt[id[i][0]],ans+=a[i][id[i][0]];
		}
		for(int c=0;c<3;++c){
			if(cnt[c]>n/2){
				for(int i=1;i<=n;++i){
					if(id[i][0]!=c)continue;
					q.push(a[i][id[i][1]]-a[i][id[i][0]]);
				}
				cl=c;
				break;
			}
		}
		if(cl!=-1)while(cnt[cl]>n/2)ans+=q.top(),q.pop(),--cnt[cl];
		printf("%lld\n",ans);
		while(!q.empty())q.pop();
		cnt[0]=0,cnt[1]=0,cnt[2]=0;
	}
	return 0;
}

