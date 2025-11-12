#include<bits/stdc++.h>
using namespace std;
#define LL long long
inline int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-'){
			f = -1;
		}
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
void print(int x){
	if(x < 0){
		putchar('-');
		x = -x;
	}
	if(x > 9){
		print(x / 10);
	}
	putchar(x % 10 + '0');
}
int T, n, g[5], ans;
struct node{
	int group, val;
} a[100005][4]; 
bool cmp1(node x, node y){
	return x.val > y.val;
}
priority_queue <pair<int, int>> q;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T --){
		cin >> n;
		ans = 0;
		memset(g, 0, sizeof(g));
		for(int i = 1; i <= n; i ++){
			a[i][1] = {1, read()};
			a[i][2] = {2, read()};
			a[i][3] = {3, read()};
			sort(a[i] + 1, a[i] + 4, cmp1);
			q.push({a[i][1].val, i});
		}
		for(int i = 1; i <= n; i ++){
			int u = q.top().first, v = q.top().second;
			q.pop();
			if(g[a[v][1].group] < n / 2){
				g[a[v][1].group] ++;
				ans += u;
				continue;
			}
			if(g[a[v][2].group] < n / 2){
				g[a[v][2].group] ++;
				ans += a[v][2].val;
				continue;
			}
			g[a[v][3].group] ++;
			ans += a[v][3].val;
		}
		print(ans);
		printf("\n");
	}
	return 0;
}


