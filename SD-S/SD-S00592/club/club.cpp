#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	long long id1,id2,del;
}a[200005];
bool cmp(node a,node b){
	return a.del>b.del;
}
void solve(){
	scanf("%d",&n);
	long long sum=0;
	for(int i=1;i<=n;i++){
		long long a1,a2,a3;
		scanf("%lld %lld %lld",&a1,&a2,&a3);
		int maxn=max({a1,a2,a3});
		if(a1==maxn){
			a[i].id1=1;
			a[i].id2=(a2>a3?2:3);
			a[i].del=maxn-max(a2,a3);
		}else if(a2==maxn){
			a[i].id1=2;
			a[i].id2=(a1>a3?1:3);
			a[i].del=maxn-max(a1,a3);
		}else{
			a[i].id1=3;
			a[i].id2=(a1>a2?1:2);
			a[i].del=maxn-max(a1,a2);
		}
		sum+=maxn;
	}
	sort(a+1,a+n+1,cmp);
	int cnt[4]={0,0,0,0};
	for(int i=1;i<=n;i++){
		if(cnt[a[i].id1]*2>=n){
			sum-=a[i].del;
			cnt[a[i].id2]++;
		}else{
			cnt[a[i].id1]++;
		}
		a[i]={0,0,0};
	}
	printf("%lld\n",sum);
	return;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}
