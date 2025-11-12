# include<bits/stdc++.h>
# define int long long
using namespace std;
const int N=1e5+5;
int n,t;
struct node{
	pair<int,int> x[3];
}a[N];
bool cmp1(pair<int,int> x,pair<int,int> y){
	return x.first>y.first;
}
bool cmp2(node x,node y){
	return x.x[1].first>y.x[1].first;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		priority_queue<int> y[3];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%lld",&a[i].x[j].first);
				a[i].x[j].second=j;
			}
			sort(a[i].x+1,a[i].x+4,cmp1);
//			printf("%lld %lld\n",a[i].x[1].first,a[i].x[1].second);
		}
		sort(a+1,a+n+1,cmp2);
		int ans=0,vis[4]={};
		for(int i=1;i<=n;i++){
			y[a[i].x[1].second].push(a[i].x[2].first-a[i].x[1].first);
			y[a[i].x[2].second].push(a[i].x[3].first-a[i].x[2].first);
			for(int j=1;j<=3;j++){
				if(vis[a[i].x[j].second]<(n/2)){
					ans+=a[i].x[j].first;
					vis[a[i].x[j].second]++;
					break;
				}else if(a[i].x[j].first>(-y[a[i].x[j].second].top())){
					ans+=a[i].x[j].first+y[a[i].x[j].second].top();
					y[a[i].x[j].second].pop();
					break;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}