#include<bits/stdc++.h>
using namespace std;
int T, n, a[100005][3], cnt[3], p[100005];
bool chk = 0;
long long ans;
int mmax(int u, int v, int w){
	return max(u, max(v, w));
}
int smax(int u, int v, int w){
	int tmp[3] = {u, v, w};
	sort(tmp, tmp + 3);
	return tmp[1];
}
bool cmp(int u, int v){
	int mu = mmax(a[u][0], a[u][1], a[u][2]) - smax(a[u][0], a[u][1], a[u][2]);
	int mv = mmax(a[v][0], a[v][1], a[v][2]) - smax(a[v][0], a[v][1], a[v][2]);
	return mu > mv;
}
int gmx(int u, int v, int w){
	if (u > v && u > w)
		return 0;
	else if (v > u && v > w)
		return 1;
	return 2;
}
int main(){
	freopen("club.in", "r", stdin);//freopen
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> T;
	while (T--){
		cin >> n;
		ans = 0;
		for (int i = 1; i <= n; i++)
			cin >> a[i][0] >> a[i][1] >> a[i][2];
		for (int i = 1; i <= n; i++)
			p[i] = i;
		sort(p + 1, p + 1 + n, cmp);
		cnt[0] = cnt[1] = cnt[2] = 0;
		ans = 0;
		for (int i = 1; i <= n; i++){
			int qwq = gmx(a[p[i]][0], a[p[i]][1], a[p[i]][2]);
			cnt[qwq]++;
			ans += mmax(a[p[i]][0], a[p[i]][1], a[p[i]][2]);
			if (cnt[qwq] == n / 2){
				for (int j = i + 1; j <= n; j++)
					a[p[j]][qwq] = -1;
				sort(p + i + 1, p + 1 + n, cmp);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}//1h 才过大样例。 
//真好笑。 
