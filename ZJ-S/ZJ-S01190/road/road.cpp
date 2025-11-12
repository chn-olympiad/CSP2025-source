#include <bits/stdc++.h>
#define ll long long
#define sc scanf
#define pr printf
#define v1 first
#define v2 second
#define IINF 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3fll
using namespace std;
const int N=1e4+30;
const int M=1e6+5;
struct node{
	int x,y;
	ll w;
	bool operator <(const node &x)const{
		return w<x.w;
	}
}inp[M];
vector<node> ed;
ll a[15][N];
ll c[15];
ll b[15];
int fa[N];
int find(int k){
	return (fa[k]==k)?(k):(fa[k]=find(fa[k]));
}
void init(int n){
	for(int i=1; i <= n; i++)fa[i]=i;
}
int n;
ll ans;
int k;
void merge(int x,int y,ll w){
	int fax=find(x),fay=find(y);
	if(fax==fay)return;
	fa[fax]=fay;
	ans+=w;
}
bool bl[15];
int p[15];
bool cmp(int x,int y){
	return b[x]>b[y];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	freopen("road4.in","r",stdin);
//	freopen("res.out","w",stdout);
	int m;
	sc("%d%d%d",&n,&m,&k);
	for(int i=1; i <= m; i++){
		sc("%d%d%lld",&inp[i].x,&inp[i].y,&inp[i].w);
		ed.push_back(inp[i]);
	}
	for(int i=1; i <= k; i++){
		sc("%lld",&c[i]);
		for(int j=1;j <= n; j++)sc("%lld",&a[i][j]),ed.push_back({i+n,j,a[i][j]});
	}
	init(n+k);
	sort(ed.begin(),ed.end());
	for(auto y:ed){
		if(y.x<=n&&y.y<=n)
			merge(y.x,y.y,y.w);
	}
	ll tmp=ans;
//	cout <<tmp <<endl;
	for(int i=1; i <= k; i++){
		init(n+k);
		ans=0;
		for(auto y:ed){
			if(y.x<=n&&y.y<=n)merge(y.x,y.y,y.w);
			else if(y.x==i+n||y.y==i+n)merge(y.x,y.y,y.w);
		}
		b[i]=tmp-ans-c[i];
	}

	for(int i=1; i <= k; i++)
		p[i]=i;
	sort(p+1,p+k+1,cmp);
	ll ans2=INF;
	ll sum=0;
	for(int i=0; i <= k; i++){
		init(n+k);
		ans=0;
		for(auto y:ed){
			if(y.x<=n&&y.y<=n)merge(y.x,y.y,y.w);
			else if((y.x>n&&bl[y.x-n])||(y.y>n&&bl[y.y-n]))merge(y.x,y.y,y.w);
		}
		ans2=min(ans2,sum+ans);
		sum+=c[p[i+1]];
		bl[p[i+1]]=1;
	}
	cout <<ans2;
	return 0;
}