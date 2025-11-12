//1s 512MB
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const int N=1e5+5,K=100;
int f[N];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q[K];
int deg[N],c[N],mn[N];
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m,k;cin >> n >> m >> k;
	for (int i=1;i<=n+k;++i) f[i]=i;
	ll ans=0;
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> kru;
	for (int i=0,u,v,w;i<m;++i){
		cin >> u >> v >> w;
		kru.emplace(w,make_pair(u,v));
	}
	for (int i=1;i<=k;++i){
		mn[i]=1e9+7;cin >> c[i];
		for (int j=1,w;j<=n;++j){
			cin >> w;
			q[i].emplace(w,j);
			mn[i]=min(mn[i],w);
		}
		pair<int,int> p=q[i].top();q[i].pop();
		kru.emplace(p.first+c[i],make_pair(i+n,p.second));
//		cout<<c[i]<<" "<<mn[i]<<"\n";
	}
	int u,v,w;
	pair<int,pair<int,int>> p;
	while (!kru.empty()){
		p=kru.top();kru.pop();
		w=p.first,u=p.second.first,v=p.second.second;
		if (u>n && !q[u-n].empty()){
			int i=u-n;
			pair<int,int> p=q[i].top();q[i].pop();
			kru.emplace(p.first,make_pair(u,p.second));//更新堆顶堆
		}
		if (find(u)==find(v)) continue;
		f[find(u)]=find(v);
		++deg[u],++deg[v];
		ans+=w;
//		cout<<u<<" "<<v<<" "<<w<<"\n";
	}
	for (int i=1;i<=k;++i) if (deg[n+i]==1) ans-=mn[i]+c[i];//好吃懒做直接不点亮它了
//	for (int i=1;i<=k;++i) cout<<deg[n+i]<<" "<<mn[i]<<" "<<c[i]<<" | ";cout<<"\n";
	cout<<ans<<"\n";
	cout.flush();
	return 0;
}
//铁衣寒枪且看龙吟对虎啸
/*
这啥？差分约束？拆点？状压？
k这么小
哦哦哦可以跑最小生成树啊。。。
最后一定是一棵树，首先对原有的城市做最小生成树
我们可以枚举乡镇，然后暴力跑Kru吗？
对于特殊性质，可以直接把所有的农村点满
这样一定是最优的，因为如果点多了也没啥事（0的边可以让他连接）
正解可不可以就是看一看是否点多了然后删去农村？
但是k<=10是个什么东西？
加上暴力这里有56分

目前的想法：
把农村的点和边也弄进来，一起跑最小生成树
然后枚举农村集合（要丢掉的），把这些丢掉后答案要变成什么
这样最多只会减少n-1条边（最劣情况就是某一个农村把所有城市连起来了）
可能构成n个连通块
此时，构成的连通块肯定是这些农村在树上的邻居然后就不会了


会不会k<=10是个假的？
为什么一定要原图是连通的？可不可以对原图求最小生成树？
在MST上的LCA链可否求？

不对啊我是sb
堆顶堆即可
让他来弄
然后最终的成果可以把农村的叶子节点给删了
就算假了也没关系
反正能够过48分
还可能骗到更高
*/