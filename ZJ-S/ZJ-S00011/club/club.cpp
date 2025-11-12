#include<cstdio>
#include<queue>
#define ll long long
using namespace std;
const int N=2e5+5;
struct person{
	ll a[5];
}p[N];
int cnt[5];
priority_queue<ll> q[5];
void work(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			scanf("%lld",&p[i].a[j]);
		}
	}
	ll ans=0;
	for(int i=1;i<=3;i++){
		cnt[i]=0;
		while(!q[i].empty()) q[i].pop();
	}
	
	for(int i=1;i<=n;i++){
		ll maxn1=0,maxn2=0;
		for(int j=1;j<=3;j++){
			if(p[i].a[j]>p[i].a[maxn2]) maxn2=j;
			if(p[i].a[maxn2]>p[i].a[maxn1]) swap(maxn2,maxn1);
		}
//		printf("%d %d\n",maxn1,maxn2);
		ans+=p[i].a[maxn1];
		cnt[maxn1]++;
		q[maxn1].push(p[i].a[maxn2]-p[i].a[maxn1]);
	}
	for(int i=1;i<=3;i++){
		if(cnt[i]*2>n){
			while(!q[i].empty() && cnt[i]*2>n){
				cnt[i]--;
				ans+=q[i].top();
				q[i].pop();
			}
			break;
		}
	}
	printf("%lld\n",ans);
}

int main(){
//	system("fc club.out club5.ans");
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(;T;T--) work();
	return 0;
}

//wotouwenjianzenmewangle
//14:55 O(n) tanxin geizuiyou tiaozhengjike

//15:06 AC
