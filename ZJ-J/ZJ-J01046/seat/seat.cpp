#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int w, id;
}a[106];
bool cmp(node a, node b){return a.w > b.w;}
signed main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n * m; i++){
		cin >> a[i].w;
		a[i].id = i;
	}
	int wz;
	sort(a + 1, a + n * m + 1, cmp);
	for(int i = 1; i <= n * m; i++){
		if(a[i].id == 1){
			wz = i;
			break;
		}
	}
	int ans2;
	if(wz % n == 0){
		cout << wz / n << " ";
		if((wz / n) % 2 == 1)ans2 = m;
		else ans2 = 1;
	}
	else{
		cout << wz / n + 1 << " ";
		if((wz / n + 1) % 2 == 1)ans2 = wz % n;
		else ans2 = m - (wz % n) + 1;
	}
	cout << ans2;
    return 0;
}
