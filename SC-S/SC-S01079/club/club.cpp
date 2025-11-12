#include <iostream> //O(TNlogN)
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#define ll long long
using namespace std;
const int MAXN=1e5+10;

int T,N,len,cnt1,cnt2,cnt3;
ll x,y,z,ans;

inline void init(){
	len=(N>>1);ans=0;
	cnt1=0;cnt2=0;cnt3=0;
}
void solve(){
	priority_queue<ll> A,B,C;
	scanf("%d",&N);
	init();
	for(int i=1;i<=N;++i){
		scanf("%lld%lld%lld",&x,&y,&z);
		if(x>=y&&x>=z){ //x最大
			++cnt1;ans+=x;
//			printf("max(%lld,%lld)-%lld=%lld\n",y,z,x,max(y,z)-x);
			A.push((max(y,z)-x));
		}
		else if(y>=x&&y>=z){ //y最大
			++cnt2;ans+=y;
			B.push((max(z,x)-y));
		}
		else{ //z最大
			++cnt3;ans+=z;
			C.push((max(x,y)-z));
		}
	}
//	printf("cnt={%d,%d,%d},ans=%lld\n",cnt1,cnt2,cnt3,ans);
	if(cnt1>len){ //A多了
		for(int i=1;i<=cnt1-len;++i){
//			printf("+%lld",A.top());
			ans+=A.top();A.pop();
		}
	}
	if(cnt2>len){ //B多了
		for(int i=1;i<=cnt2-len;++i){
//			printf("+%lld",B.top());
			ans+=B.top();B.pop();
		}
	}
	if(cnt3>len){ //C多了
		for(int i=1;i<=cnt3-len;++i){
//			printf("+%lld",C.top());
			ans+=C.top();C.pop();
		}
	}
//	printf("=%lld\n",ans);
	printf("%lld\n",ans);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}