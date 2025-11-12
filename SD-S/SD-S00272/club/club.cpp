#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int T, n, cnt[4], mx[N], a[N][4];
priority_queue <int> q;
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		int ans = 0;
		scanf("%lld",&n);
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++){
			mx[i]=0;
			for(int j=1;j<=3;j++){
				scanf("%lld",&a[i][j]);
				if(a[i][j]>=a[i][mx[i]])mx[i]=j;
			}
			ans+=a[i][mx[i]];
			cnt[mx[i]]++;
		}
		int tmp=0;
		if(cnt[1]>n/2)tmp=1;
		if(cnt[2]>n/2)tmp=2;
		if(cnt[3]>n/2)tmp=3;
		if(tmp!=0){
			for(int i=1;i<=n;i++){
				if(mx[i]!=tmp)continue;
				int res=0;
				for(int j=1;j<=3;j++){
					if(j==tmp)continue;
					res=max(res,a[i][j]);
				}
				q.push(res-a[i][tmp]);
			}
			for(int i=1;i<=cnt[tmp]-n/2;i++){
				ans+=q.top();
				q.pop();
			}
		}
		printf("%lld\n",ans);
		while(q.size())q.pop();
	}
	return 0;
}

