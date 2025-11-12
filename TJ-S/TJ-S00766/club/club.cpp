#include <bits/stdc++.h>

using namespace std;

const int N = 200099;
long long t, ans, n, a[N], b[N], c[N];

struct node{
	long long to1, to2;
	bool operator < (node other_) const{
		return max(this->to1, this->to2) < max(other_.to1, other_.to2);
	}
};

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		ans = 0;
		cin >> n;
		priority_queue<node> aq, bq, cq;
		for(int i = 1;i <= n;i++){
			cin >> a[i] >> b[i] >> c[i];
			if(c[i] == max(max(a[i], b[i]), c[i])){
				ans += c[i];
				cq.push((node){a[i] - c[i], b[i] - c[i]});
				continue;
			}
			if(b[i] == max(max(a[i], b[i]), c[i])){
				ans += b[i];
				bq.push((node){a[i] - b[i], c[i] - b[i]});
				continue;
			}
			if(a[i] == max(max(a[i], b[i]), c[i])){
				ans += a[i];
				aq.push((node){b[i] - a[i], c[i] - a[i]});
				continue;
			}
		}
		while(aq.size() > n / 2){
			node f = aq.top();
			ans += max(f.to1, f.to2);
			aq.pop();
		}
		while(bq.size() > n / 2){
			node f = bq.top();
			ans += max(f.to1, f.to2);
			bq.pop();
		}
		while(cq.size() > n / 2){
			node f = cq.top();
			ans += max(f.to1, f.to2);
			cq.pop();
		}
		cout << ans << endl;
	}
	return 0;
}










/*
3
4
0 1 0
0 1 0
0 2 0
0 2 0
4
4 2 1
3 2 4
5 3 4
3 5 1
2
10 9 8
4 0 0
*/











