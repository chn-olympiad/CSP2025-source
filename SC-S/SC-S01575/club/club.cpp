#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e5 + 10;
struct Node{
	int sum;
	int id;
	int op;
}a[N];
int sum[N][4];

bool vis[N];
int d[4][N];
int len[4];
int cl[N];

int n;
int cnt;
int ans;

bool cmp(Node x, Node y){
	return x.sum > y.sum;
}

void rd(int id, int op){
	scanf("%lld", &a[++cnt].sum);
	a[cnt].id = id;
	a[cnt].op = op;
	
	sum[id][op] = a[cnt].sum;
	
	return;
}

void init(){
	cnt = 0;
	ans = 0;
	
	len[1] = len[2] = len[3] = 0;
	
	for (int i = 1; i <= n; i++) vis[i] = false;
}

signed main(){
	freopen("club.in","r",stdin); 
	freopen("club.out","w",stdout); 
	
	int T;
	scanf("%lld", &T);
	
	while(T--){
		scanf("%lld", &n);
		
		init();
		
		for (int i = 1; i <= n; i++){
			rd(i, 1);
			rd(i, 2);
			rd(i, 3);
		}
		
		sort(a + 1, a + cnt + 1, cmp);
		
		for (int i = 1; i <= cnt; i++){
			if (vis[a[i].id]) continue;
			vis[a[i].id] = true;
			
			d[a[i].op][++len[a[i].op]] = a[i].id;
			
			ans += a[i].sum;
		}
		
		//1人数超了
		if (len[1] > n / 2){
			for (int i = 1; i <= len[1]; i++){
				int id = d[1][i];
				cl[i] = min(sum[id][1] - sum[id][2], sum[id][1] - sum[id][3]);
			} 
			
			sort(cl + 1, cl + len[1] + 1);
			
			for (int i = 1; i <= len[1] - n / 2; i++){
				ans -= cl[i];
			}
			
		}
		
		//2人数超了
		if (len[2] > n / 2){
			for (int i = 1; i <= len[2]; i++){
				int id = d[2][i];
				cl[i] = min(sum[id][2] - sum[id][1], sum[id][2] - sum[id][3]);
			} 
			
			sort(cl + 1, cl + len[2] + 1);
			
			for (int i = 1; i <= len[2] - n / 2; i++){
				ans -= cl[i];
			}
		}
		
		//3人数超了
		if (len[3] > n / 2){
			for (int i = 1; i <= len[3]; i++){
				int id = d[3][i];
				cl[i] = min(sum[id][3] - sum[id][1], sum[id][3] - sum[id][2]);
			} 
			
			sort(cl + 1, cl + len[3] + 1);
			
			for (int i = 1; i <= len[3] - n / 2; i++){
				ans -= cl[i];
			}
		} 
		
		printf("%lld\n", ans);
		
	}
	
	return 0;
} 