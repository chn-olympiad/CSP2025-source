#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
int T,n,a[N][6];//1~3满意度,4最大满意度的部门,5最大满意度和次大满意度之差
long long ans;
long long jian;
int cnt[5];
int calc(int x,int y,int z) {
	int maxn=max(max(x,y),z);
	int minn=min(min(x,y),z);
	return 2*maxn-x-y-z+minn;
}
int getidx(int x,int y,int z) {
	int maxn=max(max(x,y),z);
	if(x==maxn)
		return 1;
	if(y==maxn)
		return 2;
	if(z==maxn)
		return 3;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		cnt[1]=0;
		cnt[2]=0;
		cnt[3]=0;
		ans=0;
		jian=0;
		scanf("%d",&n);
		for(int i=1; i<=n; i++) {
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			ans+=max(max(a[i][1],a[i][2]),a[i][3]);
			a[i][4]=getidx(a[i][1],a[i][2],a[i][3]);
			cnt[a[i][4]]++;
			a[i][5]=calc(a[i][1],a[i][2],a[i][3]);
		}
		if(max(cnt[3],max(cnt[1],cnt[2]))<=(n/2)) {
			printf("%lld\n",ans);
			continue;
		}
		vector<int>q;
		int maxidx=getidx(cnt[1],cnt[2],cnt[3]);
		for(int i=1; i<=n; i++)
			if(a[i][4]==maxidx)
				q.push_back(a[i][5]);
		sort(q.begin(),q.end());
		int m=max(cnt[3],max(cnt[1],cnt[2]))-(n/2);
		for(int i=0; i<m; i++)
			jian+=q[i];
		printf("%lld\n",ans-jian);
	}
	return 0; 
}
