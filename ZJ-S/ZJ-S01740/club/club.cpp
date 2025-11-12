#include<bits/stdc++.h>
using namespace std;
const int N=1E5+5;
int n,T;
int a[N][4];
int ans,cnt[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		ans=0;
		memset(cnt,0,sizeof cnt);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		}
		priority_queue<int,vector<int>,greater<int>>q[4];
		for(int i=1;i<=n;i++){
			int mx=max({a[i][1],a[i][2],a[i][3]});
			ans+=mx;
			if(a[i][1]==mx){
				cnt[1]++;
				q[1].push(a[i][1]-max(a[i][2],a[i][3]));
			}
			else if(a[i][2]==mx){
				cnt[2]++;
				q[2].push(a[i][2]-max(a[i][1],a[i][3]));
			}
			else {
				cnt[3]++;
				q[3].push(a[i][3]-max(a[i][2],a[i][1]));
			}
		}
		if(cnt[1]<=n/2 && cnt[2]<=n/2 && cnt[3]<=n/2){
			printf("%d\n",ans);
			continue;
		}
		else {
			if(cnt[1]>n/2){
				while(cnt[1]>n/2){
					ans-=q[1].top();
					q[1].pop();
					cnt[1]--;
				}
			}
			else if(cnt[2]>n/2){
				while(cnt[2]>n/2){
					ans-=q[2].top();
					q[2].pop();
					cnt[2]--;
				}
			}
			else {
				while(cnt[3]>n/2){
					ans-=q[3].top();
					q[3].pop();
					cnt[3]--;
				}
			}
			printf("%d\n",ans);
			continue;
		}
	}
	return 0;
}

