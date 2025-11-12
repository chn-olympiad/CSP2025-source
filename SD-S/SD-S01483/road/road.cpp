#include <bits/stdc++.h>
/*
洛天依赐我力量
lxl赐我力量
珂朵莉赐我力量
奈芙莲赐我力量
瑟尼欧里斯赐我力量
二阶堂希罗赐我力量
樱羽艾玛赐我力量
ksm赐我力量
ykn赐我力量
ppp赐我力量
Roselia赐我力量
让我拿到7级钩吧！！！！！！
关注洛谷:978535(好像是)--Kayisama
*/
using namespace std;
#define lowbit(x) ((x)&(-(x)))
inline void read(){}
template <typename T,typename... R>
inline void read(T& r,R&... oth){
	r=0;T f=1;char c=getchar();
	while (c<'0' || c>'9') {
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0' && c<='9') r=(r<<3)+(r<<1)+(c&15),c=getchar();
	r*=f;
	read(oth...);
	return;
}
template<typename T>
T gcd(T a,T b){
	return b<=0?a:gcd(b,a%b);
}
template<typename T>
T exgcd(T a,T b,T& x,T& y){
	if (b<=0){
		x=1,y=0;
		return a;
	}
	T d=exgcd(b,a%b,y,x);
	y-=(a/b)*x;
	return d;
}
template<typename T>
T qpow(T a,T n,T p){
	T res=1;
	for(;n;n>>=1ll){
		if (n&1ll) res=(res*a)%p;
		a=(a*a)%p;
	}
	return res;
}
//const int luotianyi=0x66ccff
#define int long long
const int maxn=1e4+5;
int n,m,k;
struct edge{
	int u,v,w;
	friend bool operator<(edge a,edge b){
		return a.w<b.w;
	}
};
int fa[maxn],siz[maxn];//路径压缩+按秩合并 
int fd(int x){
	return fa[x]==x?x:fa[x]=fd(fa[x]);
}
void hb(int x,int y){
	x=fd(x),y=fd(y);
	if (x==y) return;
	if (siz[x]<siz[y]) swap(x,y);
	fa[y]=x;
	siz[x]+=siz[y];
 	return;
}
pair<vector<edge>,int> merge(int n,const vector<edge>& a,const vector<edge>& b){
	vector<edge> c,res;
	//双指针合并ab到c,保持有序 
	int ptra=0,ptrb=0;
	int alen=a.size(),blen=b.size();
	for (;ptra<alen && ptrb<blen;){
		//printf("++ %d %d ++\n",a[ptra].w,b[ptrb].w);
		if (a[ptra].w<b[ptrb].w) c.push_back(a[ptra]),ptra++;
		else c.push_back(b[ptrb]),ptrb++;
	}
	while (ptra<alen) c.push_back(a[ptra]),ptra++;
	while (ptrb<blen) c.push_back(b[ptrb]),ptrb++;
//	printf("\n---------------------\n");
//	for (auto i:c) printf("%d ",i.w);
//	printf("\n---------------------\n");
	int sum=0,cnt=0;//边和,边个数 
	for (int i=1;i<=n+k;i++) fa[i]=i,siz[i]=1;
	for (auto i:c){
		int u=i.u,v=i.v,w=i.w;
		u=fd(u),v=fd(v);
		if (u!=v){
			hb(u,v);
			cnt++;
			sum+=w;
			res.push_back(i);
		}
		if (cnt==n) break;
	}
//	printf("\n---------------------\n");
//	for (auto i:res) printf("%d ",i.w);
//	printf("\n---------------------\n");
	return make_pair(res,sum);
}
int ans;
int ysum;
vector<edge> bj[15];
int c[15];
int a[15][maxn];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n,m,k);
	for (int i=1;i<=m;i++){
		int u,v,w;read(u,v,w);
		bj[0].push_back({u,v,w});
	}
	sort(bj[0].begin(),bj[0].end());
	auto tmp=merge(n,bj[0],bj[1]);
	bj[0]=tmp.first;
	ans=ysum=tmp.second;
	for (int i=1;i<=k;i++){
		read(c[i]);
		for (int j=1;j<=n;j++) {
			int w;read(w);
			bj[i].push_back({i+n,j,w});
		}
		sort(bj[i].begin(),bj[i].end());
	}	
	for (int i=1;i<(1<<k);i++){
		auto tmp=make_pair(bj[0],ysum);
		int sum=0,cnt=0;
		for (int j=1;j<=k;j++){
			if (i&(1<<(j-1))){
				cnt++;
				tmp=merge(n+cnt,tmp.first,bj[j]);
				sum+=c[j];
			}
		}
		//printf("--%d %d--\n",tmp.second,sum);
		ans=min(ans,sum+tmp.second);
	}
	printf("%lld",ans);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/

//考虑直接枚举2^k种情况，对于每次情况求mst
//使用一些优化把排序和bcj变成O(n)和O(1)
//总复杂度O(2^k*nk),约等于1e8,跑不满 

//16:04 A掉所有样例 


