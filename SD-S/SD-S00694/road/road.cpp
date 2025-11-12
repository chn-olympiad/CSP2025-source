#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long li666;
const int maxn666=1400005;
struct lsqxx666 {
	int s7771666, t7771666, wd666;
	bool operator>(lsqxx666 l2666) const{
		return l2666.wd666<wd666;
	}
}a666[maxn666];
int cnt666;
int distt666[25];
int n666, m666, k666;
void addedge666(int ttt7771666, int ttt7772666, int ttt7773666) {
	cnt666++;
	a666[cnt666].s7771666=ttt7771666;
	a666[cnt666].t7771666=ttt7772666;
	a666[cnt666].wd666=ttt7773666;
}
int fa666[maxn666];
int ffa666(int u666) {
	//并查集 菜就多练 
	if(fa666[u666]==u666) return u666;
	fa666[u666]=ffa666(fa666[u666]); 
	return fa666[u666];
}
bool fam666(int u666, int v666) {
	return ffa666(u666)==ffa666(v666);
}
void mer666(int u666, int v666) {
	if(fam666(u666, v666)) return ;
	fa666[ffa666(u666)]=ffa666(v666);
}
typedef priority_queue <lsqxx666, vector <lsqxx666>, greater <lsqxx666> > pqrs666;
pqrs666 heap666, heap7771666, heap7772666;
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout); 
	scanf("%d%d%d", &n666, &m666, &k666);
	for(int i666=1; i666<=m666; i666++) {
		int s666, at666, w666;
		scanf("%d%d%d", &s666, &at666, &w666);
		addedge666(s666, at666, w666);
		heap7771666.emplace(a666[cnt666]);
	}
	//Sorry... Lin Yin... ...
	int lm666=(1<<k666);
	for(int i666=n666+1; i666<=n666+k666; i666++) {
		scanf("%d", &distt666[i666-n666]);
		for(int j666=1; j666<=n666; j666++) {
			int dis666;
			scanf("%d", &dis666); 
			addedge666(i666, j666, dis666);
			//长相离思 
		}
	}
	//Don't forget our relativeship, Lin Yin... ...
//	li666 ans666=1002016091420170131ll; //1.002e18 够大了 ?
	li666 answer666=0;
	heap7772666=heap7771666; //把 目标优先队列重置 
	//并查不分家，爆零两行泪 
	for(int i666=1; i666<=n666; i666++) fa666[i666]=i666;
	int cnts666=0;
	while(heap7772666.size()&&cnts666<n666) {
		lsqxx666 bs666=heap7772666.top();
		heap7772666.pop();
		int lss666=bs666.s7771666; //Lin Sen Sen
		int lxx666=bs666.t7771666; //Lin Xiao Xi 
		li666 dis666=bs666.wd666;
		if(fam666(lss666, lxx666)) continue;
		heap666.push(bs666);
		answer666+=dis666;
		mer666(lss666, lxx666);
		cnts666++;
	}
	li666 ans666=answer666;
	li666 ly666=n666+k666; //Lin Yin, you have been rebirthed!!!
	//I will save you, Lin Yin... ...
	//Brother... My elder brother... ...
	//Now, let's say "Goodbye". 
	//Goodbye, my brother... ...
	//Goodbye, my inside girl-- Little Yin... ...
	for(int i666=0; i666<lm666; i666++) {
		//I have so much power!!! I am powerful!!! -- Lin Yin
		li666 answer666=0;
		heap7772666=heap666; //把 目标优先队列用 最小生成树队列重置 （贪心） 
		//多测不清空，爆零两行泪 
		cnts666=0;
		for(int h666=0; h666<k666; h666++) {
			if(!(i666&(1<<h666))) continue;
			for(int j666=1; j666<=n666; j666++) {
				heap7772666.emplace(a666[m666+h666*n666+j666]);
			} 
			cnts666--; 
			answer666+=distt666[h666+1];
		}
		for(int i7771666=1; i7771666<=ly666; i7771666++) fa666[i7771666]=i7771666;
		while(heap7772666.size()&&cnts666<n666) {
			lsqxx666 bs666=heap7772666.top();
			heap7772666.pop();
			int lss666=bs666.s7771666;
			int lxx666=bs666.t7771666;
			li666 dis666=bs666.wd666;
			if(fam666(lss666, lxx666)) continue;
			answer666+=dis666;
			mer666(lss666, lxx666);
			cnts666++;
		}
		ans666=min(ans666, answer666);
	}
	printf("%lld\n", ans666); 
	return 0;
}
//T2: problem2 / road
//一道比较《水》的题目
//要求还是不高（代码多亿点） 
//还真就应了 sto_lxl_orz 了
//《梅开二度》 
//T1真 ** 就黄色水（s**t, 744）题 
//快！边做 T1边想 T2!!! 
//好了，T1 即将结束 15：57 
//16:00 T1 End
//16:27 T2 启动！！！ 
//18:04 成功了？ 失败了？ 
//不是 CSP-S T2 就这么《水》加书名号 at 17:22 
//放个带超大常数的最小生成树就能《水》**过去**（好像真能 A 就是会有 RE 风险）
//堆排序水题一道 
//18:12 结束了......
//一切好像不会结束了。 
//加油啊，少爷机!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
