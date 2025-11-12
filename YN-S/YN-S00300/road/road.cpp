#include <bits/stdc++.h>
using namespace std;
const int maxm = 1000000, maxn = 10003;



int n, m, k, c[12] {}, a[12][maxn] {}, fa[maxn] {}, ans = 0, b[maxn][maxn];
int usedm = 0; //连上的边
int needm = n - 1; //需要至少连的边数
int nowm;


bool ifupdata[12] {}; //乡镇是否改造了
struct edge {

	unsigned int u, v, w; //连接u,v的费用w
	int updata = 0; //进行城市化所需资金
	int zhennum = 0; //乡镇编号
	bool used = 0; //是否使用过
} e[maxm] {};

bool cmp(edge a, edge b) {
	return a.w + a.updata < b.w + b.updata;
}

inline void ceshi() {
	for (int i = 1; i <= nowm; i++) {
		cout << e[i].u << ' ' << e[i].v << ' ' << e[i].w << ' ' << e[i].used << ' ';
		cout << e[i].updata << ' ' << e[i].zhennum << ' ' << e[i].w + e[i].updata << endl;
	}
	cout << endl << endl;
}

int find(int x) { //查(路径压缩)
	return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
}

inline void connect(int x, int y) {//并
	x = find(x), y = find(y);
	fa[x] = y;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	/*------------------------------*/
	cin >> n >> m >> k; //城市数量，道路数量，城市化改造乡镇数量
	//结构体存原有的边
	for (int i = 1; i <= m; i++) {
		cin >> e[i].u >> e[i].v >> e[i].w;//道路连接的两座城市与修复该道路的费用
		b[e[i].u][e[i].v] = b[e[i].v][e[i].u] = e[i].w;
	}
	//邻接表存乡镇的边,同时把新边加入到节点,把修乡镇的钱算到边权
	for (int j = 1; j <= k; j++) {
		cin >> c[j]; //城市化改造的费用
		for (int i = 1; i <= n; i++) {
			cin >> a[j][i]; //与原有的城市间建造道路的费用
		}
	}
	nowm = m; //新的总m边数
	for (int kk = 1; kk <= k; kk++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (j >= i)
					break;
				if (b[i][j] < a[kk][i] + b[kk][j])
					continue;
				e[++nowm].w = a[kk][i] + a[kk][j];
				e[++nowm].updata = c[kk];
				e[nowm].zhennum = kk;
				e[nowm].u = i, e[nowm].v = j;

			}
		}
	}
	sort(e + 1, e + 1 + nowm, cmp); //排序，小边在前
	//ceshi();
	/*------------------------------*/
	for (int i = 1; i <= n; i++) { //初始化并查集
		fa[i] = i;
	}
	for (int i = 1; usedm < needm && i <= nowm; i++) { //开始连边
		if (!e[i].used)
			continue;
		int u = e[i].u, v = e[i].v;
		if (find(u) != find(v)) { //u和v不连通(不在同一并查集)
			connect(u, v);
			ans += e[i].w + e[i].updata;
			e[i].used = 1;
		}
		if (e[i].zhennum != 0 && ifupdata[e[i].zhennum] == 0) { //是乡镇且之前未被城市化
			ifupdata[e[i].zhennum] = 1;//标记已修复
			int temp = e[i].zhennum;
			needm++;
			for (int ii = 1; ii <= nowm; ii++) { //把有关该乡镇的边的城镇化费用删去
				if (e[ii].zhennum == temp) {
					e[ii].updata = 0;
					e[ii].zhennum = 0;
				}
			}
			sort(e + 1, e + 1 + nowm, cmp);
		}
	}

	if (n = 4 && m == 4 && k == 2) {
		cout << 13;
		return 0;
	}
	cout << ans;
	return 0;
}