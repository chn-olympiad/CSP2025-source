#include<iostream>
#include<algorithm>
#include<bitset>
#define ll long long
using namespace std;

const int N=1e5+5;

int T;
int n,up;
ll ans;

int cnt[4];

int b[N];

struct node{
	int v1,v2;
}e[N];

struct stu{
	int v1,v2,v3;
}a[N];

inline void getmx(ll &a,ll b){
	return a=(a>b?a:b),void();
}

inline void dfs(ll sum,int lst){
	if(lst==n)return getmx(ans,sum),void();
	if(cnt[1]<up)++cnt[1],dfs(sum+a[lst+1].v1,lst+1),--cnt[1];
	if(cnt[2]<up)++cnt[2],dfs(sum+a[lst+1].v2,lst+1),--cnt[2];
	if(cnt[3]<up)++cnt[3],dfs(sum+a[lst+1].v3,lst+1),--cnt[3];
	return ;
}

inline void solveA(){
	for(int i=1;i<=n;++i)b[i]=a[i].v1;
	sort(b+1,b+n+1,[](int x,int y){return x>y;});
	for(int i=1;i<=up;++i)ans+=b[i];
	return ;
}

inline void solveB(){
	for(int i=1;i<=n;++i)e[i].v1=a[i].v1,e[i].v2=a[i].v2;
	sort(e+1,e+n+1,[](node a,node b){return (max(a.v1,a.v2)==max(b.v1,b.v2))?(min(a.v1,a.v2)>min(b.v1,b.v2)):(max(a.v1,a.v2)>max(b.v1,b.v2));});
	for(int i=1;i<=n;++i){
		if(e[i].v1>e[i].v2){
			if(cnt[1]<up)++cnt[1],ans+=e[i].v1;
			else ++cnt[2],ans+=e[i].v2;
		}else{
			if(cnt[2]<up)++cnt[2],ans+=e[i].v2;
			else ++cnt[1],ans+=e[i].v1;
		}
	}
	return cout<<ans<<"\n",void();
}

inline void solve(){
	dfs(0,0);
	return cout<<ans<<"\n",void();
}

inline void work(){
	ans=cnt[1]=cnt[2]=cnt[3]=0;
	cin>>n;for(int i=1;i<=n;++i)cin>>a[i].v1>>a[i].v2>>a[i].v3;
	ll mx2=0,mx3=0;for(int i=1;i<=n;++i)getmx(mx2,a[i].v2),getmx(mx3,a[i].v3);
	up=(n>>1);
	if(!(mx2+mx3))solveA();
	else if(n<=10)solve();
	else if(!mx3)solveB();
	else solve();
	return void();
}

signed main(){
	freopen("club.in","r",stdin),freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>T;while(T--)work();
	return 0;
}

/*

3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

18
4
13

*/