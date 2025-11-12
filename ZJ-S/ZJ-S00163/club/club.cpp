#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define mkp make_pair
using namespace std;
const int N=1e5+10;
//xian fang,fang wan zhi hou zhi xu ba da yu n/2 de yichu jike,paixu
int t,n,a[N][4],cnt[4],vis[N],ans;
queue<int> q[4];
void init(){
	ans=0;
	memset(a,0,sizeof a);
	memset(cnt,0,sizeof cnt);
	memset(vis,0,sizeof vis);
	for(int i=1;i<=3;++i){
		while(!q[i].empty())q[i].pop();
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		init();
		scanf("%lld",&n);
		for(int i=1;i<=n;++i){
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])ans+=a[i][1],cnt[1]++,q[1].push(i);
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])ans+=a[i][2],cnt[2]++,q[2].push(i);
			else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2])ans+=a[i][3],cnt[3]++,q[3].push(i);
		}
		priority_queue<pii> qq;
		if(cnt[1]>n/2){
			while(!q[1].empty()){
				int x=q[1].front();
				q[1].pop();
				qq.push(mkp(a[x][2]-a[x][1],x));
				qq.push(mkp(a[x][3]-a[x][1],x));
			}
			while(!qq.empty()){
				int x=qq.top().second,val=qq.top().first;
				qq.pop();
				if(!vis[x])cnt[1]--,ans+=val,vis[x]=1;
				if(cnt[1]==n/2)break;
			}
		}else if(cnt[2]>n/2){
			while(!q[2].empty()){
				int x=q[2].front();
				q[2].pop();
				qq.push(mkp(a[x][1]-a[x][2],x));
				qq.push(mkp(a[x][3]-a[x][2],x));
			}
			while(!qq.empty()){
				int x=qq.top().second,val=qq.top().first;
				qq.pop();
				if(!vis[x])cnt[2]--,ans+=val,vis[x]=1;
				if(cnt[2]==n/2)break;
			}
		}else if(cnt[3]>n/2){
			while(!q[3].empty()){
				int x=q[3].front();
				q[3].pop();
				qq.push(mkp(a[x][1]-a[x][3],x));
				qq.push(mkp(a[x][2]-a[x][3],x));
			}
			while(!qq.empty()){
				int x=qq.top().second,val=qq.top().first;
				qq.pop();
				if(!vis[x])cnt[3]--,ans+=val,vis[x]=1;
				if(cnt[3]==n/2)break;
			}
		}
		while(!qq.empty())qq.pop();
		printf("%lld\n",ans);
	}
}
