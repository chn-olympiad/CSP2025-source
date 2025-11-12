#include <bits/stdc++.h>
#define int long long

using namespace std;

int T;
struct node{
	
	int x, y, z;
	
} a[200005];
int n;
int ans;
priority_queue <int> q;

void dfs (int id, int cnt1, int cnt2, int cnt3, int sum){
	
	if (cnt1 == 0 && cnt2 == 0 && cnt3 == 0){
		
		ans = max (ans, sum);
		return;
		
	}
	
	if (cnt1 > 0) dfs (id + 1, cnt1 - 1, cnt2, cnt3, sum + a[id].x);
	if (cnt2 > 0) dfs (id + 1, cnt1, cnt2 - 1, cnt3, sum + a[id].y);
	if (cnt3 > 0) dfs (id + 1, cnt1, cnt2, cnt3 - 1, sum + a[id].z);
	
}

void solve (){
	
	cin >> n;
	
	ans = -1;
	int sm = 0;
	
	for (int i = 1; i <= n; i ++){
		
		cin >> a[i].x >> a[i].y >> a[i].z;
		sm += a[i].y + a[i].z;
		
	}
	
	if (sm == 0){
		
		for (int i = 1; i <= n; i ++){
			
			q.push (a[i].y);
			
		}
		
		int cntt = n / 2;
		int h = 0;
		
		while (cntt --){
			
			h += q.top ();
			q.pop ();
			
		}
		
		cout << h << endl;
		return;
		
	}
	
	dfs (1, n / 2, n / 2, n / 2, 0);
	
	cout << ans << endl;
	
}

signed main()
{
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin >> T;
	
	while (T --){
		
		solve ();
		
	}

}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
