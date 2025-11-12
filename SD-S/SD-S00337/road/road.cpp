#include <bits/stdc++.h>
using namespace std;
int n,m,k,ans;
bool ta = 1;
const int M = 1e6 + 10,N = 1e4 + 10;
struct A{
	int a,b,c;
}qwq[M];
int a[15][N],fa[N];

vector <A> g[M];
int find(int x){
	if (fa[x] == x) return x;
	fa[x] = find(fa[x]);
	return fa[x];
}
bool p(A n1,A n2){
	return n1.c < n2.c;
}
void klska(){
	for (int i = 1;i <= n;i ++){
		fa[i] = i;
	}
	sort(qwq + 1,qwq + m + 1,p);
	int cnt = 0;
	for (int i = 1;i <= m;i ++){
		int fx = find(qwq[i].a),fy = find(qwq[i].b);
		if (fx == fy) continue;
		fa[fx] = fy;
		ans += qwq[i].c;
		cnt ++;
		if (cnt == n - 1){
			break;
		}		
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i = 1;i <= m;i ++){
		cin >> qwq[i].a >> qwq[i].b >> qwq[i].c;
		a[qwq[i].a][qwq[i].b] = qwq[i].c;
		a[qwq[i].b][qwq[i].a] = qwq[i].c;
	}
	for (int i = 1;i <= k;i ++){
		cin >> a[i][1];
		if (a[i][1] != 0) ta = 0;
		for (int j = 2;j <= n + 1;j ++){
			cin >>a[i][j];
		}
	}
	klska();
	cout << ans;
	return 0;
}
