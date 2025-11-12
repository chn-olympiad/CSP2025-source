#include<bits/stdc++.h>
//#define int long long
using namespace std;
#define fi first
#define se second
#define mkp make_pair
#define pb emplace_back
#define ep emplace
#define Endl putchar('\n')
#define Space putchar(' ')
typedef long long ll;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const ll Inf=0x3f3f3f3f3f3f3f3f;
template<typename T> inline void read(T &s){
	s=0;int c=getchar();bool f=0;
	while(!isdigit(c))f^=(c=='-'),c=getchar();
	while(isdigit(c))s=(s<<1)+(s<<3)+(c^48),c=getchar();
}
template<typename T> inline void write(T x){
	static int St[40],Top=0;
	if(x<0)putchar('-'),x=-x;
	do St[++Top]=x%10,x/=10; while(x);
	while(Top)putchar(St[Top--]^48);
}
void read(char &c){do c=getchar(); while(isspace(c));}
template<typename type,typename... T> inline void read(type &x,T&...y){read(x);read(y...);}
const int N=1e5+5;
int n;pii a[N][3];
vector<int> vt[3];
void solve(){
	for(int i=0;i<3;i++)vt[i].clear();
	read(n);ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++)read(a[i][j].fi),a[i][j].se=j;
		sort(a[i],a[i]+3);
		vt[a[i][2].se].pb(i);ans+=a[i][2].fi;
	}
	int pos=-1;
	for(int i=0;i<3;i++)if(vt[i].size()>n/2)pos=i;
	if(!~pos)return write(ans),Endl,void();
	priority_queue<int> q;
	for(int i:vt[pos]){
		q.push(a[i][1].fi-a[i][2].fi);
	}
	int cnt=vt[pos].size();
	while(cnt>n/2){
		ans+=q.top();q.pop();cnt--;
	}
	write(ans),Endl;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);cout.tie(nullptr);
	int T=1;read(T);
	while(T--){
		solve();
	}
	return 0;
}

