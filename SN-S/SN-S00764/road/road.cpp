#include<bits/stdc++.h>
using namespace std;

/*
整理思路：
n个城市m条边，每个边都有一个边权。
同时有k个点，花费c[j]就可以激活j这个点，并且用a[j][i]的边权值连边。
我的想法：最小生成树（优先队列、并查集）
先维护bool确定k中某个点是否被激活，未被激活的话它和别的点权值a[j][i] + c[j]，激活只有a[j][i]。
同时用w[i]（边权值）与上述进行最小生成树。 

对于激活我没什么思路，注意到存在8个检查点（4 * 8 = 32），都是c[i] = 0。
那么我们去掉激活那一步，就可以用差冰机来做了
但是，乡村只是中转点。所以我们可以通过乡村构建起来任意两个城市之间的一条路径（有种floyd的感觉）
这样的话时间复杂度k * n * n 10 ^ 9超了，损失4分，还是看15/16往前的吧。
k * n * n:10 ^ 7，空间n * n + m = 10^6，刚好够，得到28分。 
*/

int n,m,k;//n个城市,m条边，k个乡村
int F[10010],size[10010];//代表元，长度 
int a[12][10010],c[12];

struct Node {
	int u,v,w;//u <->v，权值w 
};

struct cmp {
	bool operator() (Node x,Node y) {//要小跟对 
		return x.w > y.w;
	}
};

priority_queue<Node,vector<Node>,cmp> Q;//这是一个以边权值为判断标准的 小根堆 

void build() {
	for(int i = 1;i<=n;i++) {
		F[i] = i;
		size[i] = 1;
	}
}

int find(int x) {
	if(x == F[x])
		return F[x];
	else
		return F[x] = find(F[x]);
}

void unionn(int x,int y) {//传入代表元，也就是在外面find过了 
	if(size[x] > size[y]) swap(x,y);//x < y
	F[x] = y;
	size[y] += size[x];
}

void add_edge() {
	for(int i = 1;i<=n - 1;i++)
		for(int j = i + 1;j<=n;j++) {
			int minlen = 1e9;
			for(int ik = 0;ik<k;ik++)
				minlen = min(minlen,a[ik][i] + a[ik][j]);
			Node temp;
			temp.u = i;temp.v = j;temp.w = minlen;
			Q.push(temp);
		}
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 0;i<m;i++) {
		int ui,vi,wi;//u <- w -> v
		cin>>ui>>vi>>wi;
		Node temp;
		temp.u = ui;temp.v = vi;temp.w = wi;
		Q.push(temp);
	}
	for(int i = 0;i<k;i++) {
		cin>>c[i];
		for(int j = 1;j<=n;j++)
			cin>>a[i][j];
	}
	//添加中转点实现的边
	add_edge();
	//现在实现最小生成树。
	//可以维护一个cnt变量，检查现在联通了多少点了，如果cnt = n立即结束并且输出ans
	int cnt = 0,ans = 0;
	build();
	while(!Q.empty() && cnt < n) {
		Node edge = Q.top();
		Q.pop();
		int x = find(edge.u);
		int y = find(edge.v);
		if(x == y)
			continue;
		unionn(x,y);
//		cout<<"链接"<<x<<","<<y<<",花费"<<edge.w<<endl;
		cnt = max(size[x],size[y]);
		ans += edge.w;
	} 
	cout<<ans;
	return 0;
}
