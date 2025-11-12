#include<bits/stdc++.h>
using namespace std;
int n , m , k , tot;
int pre[10005];
bool vis[10005];
map<int , int> ma;
struct node{
	int x , y , z;
}a[10000005];
bool cmp(node a , node b) {
	return a.z < b.z;
}
int Find(int x) {
	if(x == pre[x]) return x;
	else return pre[x] = Find(pre[x]);
}
bool Union(int x , int y) {
	int xx = Find(x);
	int yy = Find(y);
	if(xx == yy) {
		return 0;
	}
	pre[xx] = yy;
	return 1;
}
int main() {
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	cin >> n >> m >> k;
	for(int i = 1 ; i <= n ; i++) pre[i] = i;
	for(int i = 1 ; i <= m ; i++) {
		cin >> a[i].x >> a[i].y >> a[i].z;
	}
	if(k == 0) {
		sort(a + 1 , a + m + 1 , cmp);
		int cnt = 0 , sum = 0;
		for(int i = 1 ; i <= m ; i++) {
			if(cnt == n - 1) break;
			int x = a[i].x , y = a[i].y;
			if(Union(x , y)) {
				sum = sum + a[i].z;
				cnt++;
			}
		}
		cout << sum ;
	}else {
		int x , y , tot = m , cnt = 0 , sum = 0;
		for(int i = 1 ; i <= k ; i++) {
			cin >> x;
			for(int j = 1 ; j <= n ; j++) {
				cin >> y;
				ma[j] = y;
			}
			for(int j = 1 ; j <= n ; j++) {
				for(int k = 1 ; k <= n ; k++) {
					if(j == k) continue;
					tot++;
					a[tot].x = j , a[tot].y = k , a[tot].z = ma[j] + ma[k] + x;
				}
			}
		}
		sort(a + 1 , a + tot + 1 , cmp);
		for(int i = 1 ; i <= tot ; i++) {
			if(cnt == n - 1) break;
			int x = a[i].x , y = a[i].y;
			if(Union(x , y)) {
				sum = sum + a[i].z;
				cnt++;
			}
		}
		cout << sum;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 5 0
3 2 6
1 4 6
2 3 7
4 2 5
4 3 4
*/
