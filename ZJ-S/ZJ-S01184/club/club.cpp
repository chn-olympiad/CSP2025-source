#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int a[N][5];
void solved(){
	int n;
	memset(a, 0, sizeof a);
	cin >> n;
	priority_queue<int> pq[3];
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= 3; j++){
			cin >> a[i][j];
		}
	}
	long long ans = 0;
	for(int i = 1; i <= n; i++){
		int max1 = 0;
		int max2 = 0;
		int maxi1 = 0;
		for(int j = 1; j <= 3; j++){
			if(max1 <= a[i][j]){
				max2 = max1;
				max1 = a[i][j];
				maxi1 = j;
			}
			else if(max2 <= a[i][j]){
				max2 = a[i][j];
			}
		}
		ans += max1;
		pq[maxi1-1].push(max2-max1);
		if(pq[maxi1-1].size() > n/2){
			ans += pq[maxi1-1].top();
			pq[maxi1-1].pop();
		}
	}
	cout << ans << "\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		solved();
	}
	return 0;
} 
