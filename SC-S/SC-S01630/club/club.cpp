#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using db = double;
#define rep(i, l, r) for(int i = (l), END##i = (r); i <= END##i; ++i)
#define per(i, r, l) for(int i = (r), END##i = (l); i >= END##i; --i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define ML debug("\n%.2lf MB\n", (&Med-&Mst)/1024.0/1024)
#define TL debug("\n%.2lf s\n", 1.0*clock()/CLOCKS_PER_SEC)
#define fileI(x) freopen(x, "r", stdin)
#define fileO(x) freopen(x, "w", stdout)
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define pq priority_queue
bool Mst;
const int N=1e5+5;
int n,a[N][3],cnt[3];
int Get(int c[3]){
	int res=-1,ans=0;
	rep(i,0,2){
		if(c[i]>res){
			res=c[i];
			ans=i;
		}
	}
	return ans;
}
vector<int> S[3];
pq<int> que;
void Sol(){
	scanf("%d",&n);

	while(!que.empty())que.pop();
	S[0].clear();
	S[1].clear();
	S[2].clear();
	cnt[0]=cnt[1]=cnt[2]=0;

	rep(i,1,n)rep(j,0,2)scanf("%d",&a[i][j]);
	ll ans=0;
	rep(i,1,n){
		int p=Get(a[i]);
		S[p].pb(i);
		ans+=max({a[i][0],a[i][1],a[i][2]});
	}
	bool fl=1;
	rep(i,0,2)if(S[i].size()>n/2){
		fl=0;
		break;
	}
	if(fl){
		printf("%lld\n",ans);
		return;
	}
	if(S[0].size()>n/2){
		int k=S[0].size()-n/2;
		for(int x:S[0]){
			que.push(max(a[x][1],a[x][2])-a[x][0]);
		}
		while(k--){
//			assert(!que.empty());
			ans+=que.top();
			que.pop();
		}
	}
	if(S[1].size()>n/2){
		int k=S[1].size()-n/2;
		for(int x:S[1]){
			que.push(max(a[x][0],a[x][2])-a[x][1]);
		}
		while(k--){
//			assert(!que.empty());
			ans+=que.top();
			que.pop();
		}
	}
	if(S[2].size()>n/2){
		int k=S[2].size()-n/2;
		for(int x:S[2]){
			que.push(max(a[x][0],a[x][1])-a[x][2]);
		}
		while(k--){
//			assert(!que.empty());
			ans+=que.top();
			que.pop();
		}	
	}
	printf("%lld\n",ans);
}
bool Med;
int main(){
	fileI("club.in");
	fileO("club.out");
//	ML;
	int T;
	scanf("%d",&T);
	while(T--)Sol();
//	TL;
	return 0;
}
