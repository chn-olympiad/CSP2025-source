#include<bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 100050;

int t, n, op, ans;
int arr[N][3], cnt[3], mx[N], c[N]; 
priority_queue<int, vector<int>, greater<int> > q;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t --){
		cin >> n;
		ans = 0;
		while(!q.empty()) q.pop();
		cnt[0] = cnt[1] = cnt[2] = 0;
		for(int i = 1; i <= n; i ++){
			cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
			ans += max({arr[i][0], arr[i][1], arr[i][2]});
			if(arr[i][0] >= arr[i][1] && arr[i][0] >= arr[i][2]){
				mx[i] = 0;
				cnt[0] ++;
				c[i] = min(arr[i][0] - arr[i][1], arr[i][0] - arr[i][2]);
			}
			else if(arr[i][1] >= arr[i][0] && arr[i][1] >= arr[i][2]){
				mx[i] = 1;
				cnt[1] ++;
				c[i] = min(arr[i][1] - arr[i][0], arr[i][1] - arr[i][2]);
			}
			else{
				mx[i] = 2;
				cnt[2] ++;
				c[i] = min(arr[i][2] - arr[i][0], arr[i][2] - arr[i][1]);
			}
		}
		op = -1;
		if(cnt[0] > n / 2) op = 0;
		if(cnt[1] > n / 2) op = 1;
		if(cnt[2] > n / 2) op = 2;
		if(op == -1){
			cout << ans << '\n';
			continue;
		}
		for(int i = 1; i <= n; i ++)
			if(mx[i] == op)
				q.push(c[i]);
		for(int i = 1; i <= cnt[op] - n / 2; i ++){
			ans -= q.top();
			q.pop();
		}
		cout << ans << '\n';
	} 
	return 0;
}