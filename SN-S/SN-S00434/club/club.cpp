#include <bits/stdc++.h>

using namespace std;

int x, y, tp;

struct Node {
	
	int a, b;
};

inline bool cmp(const Node& a, const Node& b) {
	return a.b > b.b;
}

bool cmp1 (const vector<Node>& a, const vector<Node>& b) {
	if (a[0].b != b[0].b)
		return a[0].b > b[0].b;
		
	else if (a[1].b != b[1].b)
		return a[1].b > b[1].b;
		
	else
		return a[2].b> b[2].b;
}

void find_max(const vector <int>& a) {
	
	for (int i = 0; i < a.size(); i++)
		if (a[i] > a[tp])
		tp = i;
}

void find_max(const vector <vector <Node> >& a) {
	
	for (int i = 0;i < a.size(); i++) {
		
		if (a[i][1].b > a[x][1].b)
			x = i;
		
		if (a[i][2].b > a[y][2].b)
			y = i;
	}
}
	
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cout.tie(0), cin.tie(0);
	
	int t;
	cin >> t;
	
	while (t--) {
		
		int n;
		cin >> n;
		int mx = n / 2;
		int sum = 0;
		
		int arr[3] = { 0, 0, 0 };
		vector <vector <Node> > vec(n, vector <Node> (3));
		vector <int> dp;
		
		for (int i = 0; i < n; i++) {
			
			cin >> vec[i][0].b >> vec[i][1].b >> vec[i][2].b;
			vec[i][0].a = 0, vec[i][1].a = 1, vec[i][2].a = 2;
			
			sort (vec[i].begin(), vec[i].end(), cmp);
		}
		
		sort (vec.begin(), vec.end(), cmp1);
		
		dp.push_back(vec[0][0].b);
		arr[vec[0][0].a]++;
		
		for (int  i = 1; i < n; i++) {
			
			if (arr[vec[i][0].a] < mx) {
				
				dp.push_back(vec[i][0].b);
				arr[vec[i][0].a]++;
			}
			
			else  {
				find_max(vec);
				find_max(dp);
				
				int mx2, val, num, mx1, val1;
				
				if (vec[x][1].b > vec[y][2].b) {
					
					mx2 = vec[x][1].b;
					val = 1;
					num = x;
				}
				
				else {
					
					mx2 = vec[y][2].b;
					val = 2;
					num = y;
				}
				
				if (vec[i][1].b > vec[i][2].b) {
					
					mx1 = vec[i][1].b;
					val1 = 1;
				}
				
				else {
					
					mx1 = vec[i][2].b;
					val1 = 2;
				}
				
				if (vec[i][0].b + mx2 > dp[tp] + mx1) {
				
					dp[tp] = mx2;     arr[vec[num][val].a]--;
					dp.push_back(vec[i][0].b);     arr[vec[i][0].a]++;
				}
				
				else {
					dp.push_back(mx2);
					arr[vec[i][val1].a]++;
				}
			}
		}
		
		for (int i = 0; i < dp.size(); i++) 
			sum += dp[i];
		
		cout << sum << '\n';
	}
	
	return 0;
}
