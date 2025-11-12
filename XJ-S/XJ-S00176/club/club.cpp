#include<bits/stdc++.h> 

using namespace std;

struct node{
	int v, idx;
}a[4][10010];
int mxx[100010];
int mxis[100100];

int cmp(node a, node b) {
	return a.v > b.v; 
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		
		int ans = 0;
		//mmxi[1],mmxi[2], mmxi[3] = n / 2;
		for (int i = 0;i < n; i++) {
			cin >> a[1][i].v >> a[2][i].v >> a[3][i].v;
			a[1][i].idx = i, a[2][i].idx = i, a[3][i].idx = i;
			
		}
		for (int i = 0;i < n; i++) {
			int mx = -1, mxi;
			for (int j = 1; j < 4; j++) {
				mx = max(mx, a[j][i].v);
				mxi = a[j][i].idx;
			}
			mxx[i] = mx;
			mxis[i] = mxi;
		}
		
		sort(a[1], a[1]+n, cmp);
		
		for (int i = 0;i < 2; i++) {
			if (a[1][i].v == mxx[a[1][i].idx]){
				ans += a[1][i].v;
				a[2][i].v = 0;
				a[3][i].v = 0;
			}
		}
		
		sort(a[2], a[2]+n, cmp);
		
		for (int i = 0;i < 2; i++) {
			if (a[2][i].v == mxx[a[2][i].idx]){
				ans += a[2][i].v;
				a[2][i].v = 0;
				a[3][i].v = 0;
			}
		}
		
		sort(a[3], a[3]+n, cmp);
		
		for (int i = 0;i < 2; i++) {
			if (a[3][i].v == mxx[a[3][i].idx]){
				ans += a[3][i].v;
				a[2][i].v = 0;
				a[3][i].v = 0;
			}
		}
		
		cout << ans << endl;
	}
	
	return 0;
} 
