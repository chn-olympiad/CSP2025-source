/*又只剩下10min了,倒闭了,再见吧,估计没有一等了 */
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define ll long long
using namespace std;
constexpr ll MAXN=205,N=1e5+10;
ll _,n,a[N][5],dp[MAXN][101][101];
struct node{
	ll dlt,id;
	friend bool operator <(const node A,const node B){return A.dlt>B.dlt;}
};
inline ll reads(){
	char c=getchar();
	ll x=0,f=1;
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c-'0');
		c=getchar();
	}return x*f;
}inline void files(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
}
namespace AAA{
	void solve(){
		memset(dp,0,sizeof(dp));
		ll ans=0;
		for(ll i=1;i<=n;i++){
			for(ll A=0;A<=n/2;A++){
				for(ll B=0;B<=n/2;B++){
					if(A+B>i) continue;ll C=i-A-B;
					if(C>n/2) continue;
					if(A>0) dp[i][A][B]=max(dp[i][A][B],dp[i-1][A-1][B]+a[i][1]);
					if(B>0) dp[i][A][B]=max(dp[i][A][B],dp[i-1][A][B-1]+a[i][2]);
					if(C>0) dp[i][A][B]=max(dp[i][A][B],dp[i-1][A][B]+a[i][3]);
				}
			}
		}for(ll A=0;A<=n/2;A++){
			for(ll B=0;B<=n/2;B++){
				ll C=n-A-B;
				if(C>n/2) continue;
				ans=max(ans,dp[n][A][B]);
			}
		}printf("%lld\n",ans);
	}
}
namespace BBB{
	void solve1(){
		ll ans=0;
		priority_queue<ll> q;
		for(ll i=1;i<=n;i++) q.push(a[i][1]);
		for(ll i=1;i<=n/2;i++) ans+=q.top();q.pop();
		printf("%lld\n",ans);
	}void solve2(){
		ll ans=0;
		priority_queue<node> q[3];
		for(ll i=1;i<=n;i++){
			if(a[i][1]>a[i][2]) q[1].push(node{a[i][1]-a[i][2],i});
			else q[2].push(node{a[i][2]-a[i][1],i});
			if(q[1].size()>n/2){
				ll p=q[1].top().id;q[1].pop();
				q[2].push(node{a[p][2]-a[p][1],p});
			}
			if(q[2].size()>n/2){
				ll p=q[2].top().id;q[2].pop();
				q[1].push(node{a[p][1]-a[p][2],p});
			}
		}while(!q[1].empty()) ans+=a[q[1].top().id][1],q[1].pop();
		while(!q[2].empty()) ans+=a[q[2].top().id][2],q[2].pop();
		printf("%lld\n",ans);
	}void solve3(){
		ll ans=0;
		for(ll i=1;i<=n;i++) ans+=max(a[i][1],max(a[i][2],a[i][3]));
		printf("%lld\n",ans);
	}
}
signed main(){//file LL MLE WA
	files();
	_=reads();
	while(_--){
		n=reads();bool flg1=1,flg2=1;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=3;j++){
				a[i][j]=reads();
				if(a[i][3]) flg2=0;
				if(a[i][2]) flg1=0;
			}
		}if(n<=200){
			using namespace AAA;
			solve();
		}else if(flg1&&flg2){
			using namespace BBB;
			solve1();
		}else if(flg2){
			using namespace BBB;
			solve2();
		}else{
			using namespace BBB;
			solve3();
		}
	}
	return 0;
}
/*
1
21
2
10 0 0
14 0 0
10 0 0
14 0 0
*/
