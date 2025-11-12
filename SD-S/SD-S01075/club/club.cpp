#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int t, n, ans, b[N];
struct G{
	int x, y, z, m;
}a[N];
bool cmp1(G a, G b){
	return a.x > b.x;
}
void bfs(int pos){
	if(pos == n){
		int sum = 0, x = 0, y = 0, z = 0;
		for(int i = 1; i <= n; i++){
			if(b[i] == 1){
				sum+=a[i].x;
				x++;
			}
			else if(b[i]== 2){
				sum+= a[i].y;
				y++;
			}
			else{
				sum+=a[i].z;
				z++;
			} 
		}
		if(x <= n / 2 && y <= n / 2 && z <= n / 2){
			ans = max(ans, sum);
		}
		return ;
	}
	else{
		pos++;
		b[pos] = 1;
		bfs(pos);
		b[pos] = 2;
		bfs(pos);
		b[pos] = 3;
		bfs(pos);
		b[pos] = 0;
	}
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		cin >> n;
		bool ok1 = 1, ok2 = 1;
		ans = 0;
		for(int i = 1; i <= n; i++){
			cin >> a[i].x >> a[i].y >> a[i].z;
			if(a[i].y != a[i].z) ok1 = 0;
			
		}
		if(ok1 == 1){
			sort(a + 1, a + 1 + n, cmp1);
			for(int i = 1; i <= n / 2; i++){
				ans += a[i].x;
			}
		}
		else bfs(0);
		cout << ans << '\n';
	}
	return 0;
}
