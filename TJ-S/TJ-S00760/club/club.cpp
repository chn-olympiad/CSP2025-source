#include <bits/stdc++.h>
using namespace std;

int maxx(int a, int b, int c){
	if(a >= b && a >= c) return a;
	if(b >= a && b >= c) return b;
	if(c >= a && c >= b) return c;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int bod = n / 2;
		int a, b, c;
		priority_queue<int> maxa, maxb, maxc;
		for(int i = 1; i <= n ;i++){
			cin >> a >> b >> c;
			maxa.push(a);
			maxb.push(b);
			maxc.push(c);
		}
		int fa = 0, fb = 0, fc = 0;
		int sum = 0;
		while(n){
			int maxn;
			if(fa<bod && fb<bod && fc<bod) maxn = maxx(maxa.top(), maxb.top(), maxc.top());
			else if(fa<bod && fb<bod) maxn = max(maxa.top(), maxb.top());
			else if(fa<bod && fc<bod) maxn = max(maxa.top(), maxc.top());
			else if(fb<bod && fc<bod) maxn = max(maxb.top(), maxc.top());
			else if(fa<bod) maxn = maxa.top();
			else if(fb<bod) maxn = maxb.top();
			else if(fc<bod) maxn = maxc.top();
			if(maxn == maxa.top()){
				sum += maxa.top();
				maxa.pop();
				fa++;
				n--;
			}else if(maxn == maxb.top()){
				sum += maxb.top();
				maxb.pop();
				fb++;
				n--;
			}else if(maxn == maxc.top()){
				sum += maxc.top();
				maxc.pop();
				fc++;
				n--;
			}
		}
		cout << sum << "\n";
	}
	
	return 0;
}
