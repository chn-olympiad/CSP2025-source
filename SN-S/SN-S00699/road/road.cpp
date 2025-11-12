#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,c[12],a[12][10005],fa[10005],ans = 0x3f3f3f3f3f3f3f3f;
bool vis[15][1005];
struct edge{
	int st,en,val,fr;
}b[1000005];
bool operator < (edge a,edge b){
	return a.val < b.val;
}
int find(int x){
	if(x == fa[x]){
		return x;
	}
	return fa[x] = find(fa[x]);
}
void merge(int x,int y){
	x = find(x),y = find(y);
	fa[x] = y;
}
int kru(){
	for(int i = 1;i <= n;i++){
		fa[i] = i;
	}
	int ans = 0,sum = 0;
	for(int i = 1;i <= m;i++){
		if(sum >= n - 1){
			break;
		}
		if(find(b[i].st) != find(b[i].en)){
			ans += b[i].val;
			merge(b[i].st,b[i].en);
			sum++;
		}
	}
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		cin >> b[i].st >> b[i].en >> b[i].val;
	}
	sort(b + 1,b + m + 1);
	for(int i = 1;i <= k;i++){
		cin >> c[i];
		bool flag = (c[i] == 0);
		for(int j = 1;j <= n;j++){
			cin >> a[i][j];
			flag &= (a[i][j] == 0);
		}
		if(flag){
			cout << 0 << endl;
			return 0;
		}
	}
	cout << kru();
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
