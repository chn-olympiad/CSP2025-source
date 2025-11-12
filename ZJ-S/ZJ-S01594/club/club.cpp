#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][4],ans;
queue<int> s1;
queue<int> s2;
queue<int> s3;
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		for(int i = 1; i <= n; i++){
			if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3] && s1.size() < n/2){
				s1.push(a[i][1]);
				ans += a[i][1];
			}
			if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3] && s2.size() < n/2){
				s2.push(a[i][2]);
				ans += a[i][2];
			}
			if(a[i][3] >= a[i][2] && a[i][3] >= a[i][1] && s3.size() < n/2){
				s3.push(a[i][3]);
				ans += a[i][3];
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
