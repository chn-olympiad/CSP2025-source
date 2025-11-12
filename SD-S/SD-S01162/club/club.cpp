#include <bits/stdc++.h>
#define Ios(a) ios::sync_with_stdio(a); cin.tie(a)
#define rep(i, e, p) for(int i = (e); i <= (p); ++i)
using namespace std;
typedef long long lint;
const int N = 1e5 + 10;
int t, n, a[N][3], cnt = 0;
lint sum1, sum2, sum3, ans;
priority_queue<lint> q;
void Clear(){while(!q.empty()) q.pop();}
lint average(lint sum){
	cnt = 0;
	while(cnt < n){
		lint u = q.top(); q.pop();
		if(cnt >= (n >> 1) && u < 0) break;
		sum += u; cnt++;
	} return sum;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	 cin >> t;
	while(t--){
		cin >> n;
		rep(i, 1, n) cin >> a[i][0] >> a[i][1] >> a[i][2];
		
		sum1 = 0; Clear();
		rep(i, 1, n){
			sum1 += a[i][0];
			lint xm = max(a[i][1] - a[i][0], a[i][2] - a[i][0]);
			q.push(xm);
		} sum1 = average(sum1);
		
		sum2 = 0; Clear();
		rep(i, 1, n){
			sum2 += a[i][1];
			lint xm = max(a[i][0] - a[i][1], a[i][2] - a[i][1]);
			q.push(xm);
		} sum2 = average(sum2);
		
		sum3 = 0; Clear();
		rep(i, 1, n){
			sum3 += a[i][2];
			lint xm = max(a[i][0] - a[i][2], a[i][1] - a[i][2]);
			q.push(xm);
		} sum3 = average(sum3);
		
		ans = max(sum1, max(sum2, sum3));
		cout << ans << "\n";
	}
	return 0;
} 
