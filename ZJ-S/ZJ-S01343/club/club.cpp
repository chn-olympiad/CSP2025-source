#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+50;
struct xy{
	long long a,b,c;
}a[N];
long long t,n,ans,cnt[5];
priority_queue<long long>q[5];
long long t1,t2;
void f(long long x){
	while(cnt[x]>n/2&&!q[x].empty()){
		t1=q[x].top();
		ans+=t1;
		q[x].pop();
		cnt[x]--;
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		while(!q[1].empty())q[1].pop();
		while(!q[2].empty())q[2].pop();
		while(!q[3].empty())q[3].pop();
		cnt[1]=cnt[2]=cnt[3]=ans=0;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].a,&a[i].b,&a[i].c);
			if(a[i].a>=a[i].b&&a[i].a>=a[i].c){
				ans+=a[i].a;
				cnt[1]++;
				q[1].push(-(a[i].a-max(a[i].b,a[i].c)));
			}
			else if(a[i].b>=a[i].a&&a[i].b>=a[i].c){
				ans+=a[i].b;
				cnt[2]++;
				q[2].push(-(a[i].b-max(a[i].a,a[i].c)));
			}
			else{
				ans+=a[i].c;
				cnt[3]++;
				q[3].push(-(a[i].c-max(a[i].b,a[i].a)));
			}
		}
		if(cnt[1]>n/2){
			f(1);
		}
		else if(cnt[2]>n/2){
			f(2);
		}
		else if(cnt[3]>n/2){
			f(3);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
