#include<bits/stdc++.h>
using namespace std;
int n, m, k;
int fa[10050];
struct rd{
	int x, y, di;
};
rd mp[1000010];
rd rmp[1000010];
int cnt;
int fat(int x){
	if (fa[x] == x) return x;
	fa[x] = fat(fa[x]);
	return fa[x];
}
bool cmp(rd a, rd b){
	return a.di < b.di;
}
long long ans;
int cntn;
int newcity[15][10010];
bool touse[15];
void vali(){
	cnt = m;
	int ctycnt = 0;
	long long moneytu = 0;
	for (int i = 1;i <= k;i ++){
		if (touse[i]){
			ctycnt += 1;
			for (int j = 1;j <= n;j ++){
				cnt ++;
				mp[cnt].x = n + ctycnt;
				mp[cnt].y = j;
				mp[cnt].di = newcity[i][j];
			}
			moneytu += newcity[i][0];
		}
	}
	if (ans != -1 && moneytu > ans) return;
	for (int i = 1;i <= m;i ++){
		mp[i] = rmp[i];
	}
	sort(mp + 1, mp + 1 + cnt, cmp);
	for (int i = 1;i <= n + ctycnt;i ++){
		fa[i] = i;
	}
	for (int i = 1;i <= cnt;i ++){
		if (fat(mp[i].x) != fat(mp[i].y)){
			moneytu += mp[i].di;
			fa[fat(mp[i].x)] = fat(mp[i].y);
//			cout<<mp[i].x<<mp[i].y<<mp[i].di<<endl;
		}
	}
	for (int i = 2;i <= n + ctycnt;i ++){
		if (fat(i) != fat(i - 1)){
			return ;
		}
	}
	if (ans == -1) ans = moneytu;
	else ans = min(moneytu, ans);
//	cout<<"ans:"<<ans<<endl;
	return ;
}
void dfs(int x){
	if (x > k){
		vali();
		return;
	}
	dfs(x + 1);
	cntn += newhouse[x][0];
	if (ans != -1 && cntn >= ans){
		cntn -= newhouse[x][0];
		return;
	}
	touse[x] = true;
	dfs(x + 1);
	touse[x] = false;
	cntn -= newhouse[x][0];
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1;i <= n;i ++){
		fa[i] = i;
	}
	ans = -1;
	for (int i = 1;i <= m;i ++){
		scanf("%d%d%d", &rmp[i].x, &rmp[i].y, &rmp[i].di);
	}
	for (int i = 1;i <= k;i ++){
		scanf("%d", &newcity[i][0]);
		for (int j = 1;j <= n;j ++){
			scanf("%d", &newcity[i][j]);
		}
	}
	dfs(1);
	printf("%lld", ans);
	return 0;
}


