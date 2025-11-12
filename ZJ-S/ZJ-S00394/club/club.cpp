#include<bits/stdc++.h>
using namespace std;
#define LL long long
priority_queue< int > q[3];
const int N = 1e5 + 10;
int a[N][3];
LL ans = 0;
int n;
void init(){
	ans = 0;
	for(int i=0;i<3;i++)
		while(!q[i].empty()) q[i].pop();
	return ;
}
void solve(){
	init();
	cin >> n;
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++)
			cin >> a[i][j];
	}
	for(int i=1;i<=n;i++){
			int t = 0;
			if(a[i][1] > a[i][t]) t = 1;
			if(a[i][2] > a[i][t]) t = 2;
			ans += ( long long )(a[i][t]);
			if(t == 0){
				q[t].push(max(a[i][1]-a[i][0],a[i][2]-a[i][0]));
			}
			else if(t == 1){
				q[t].push(max(a[i][0]-a[i][1],a[i][2]-a[i][1]));
			}
			else if(t == 2){
				q[t].push(max(a[i][0]-a[i][2],a[i][1]-a[i][2]));
			}
	}
	for(int i=0;i<3;i++){
		if(q[i].size() > n/2){
			while(q[i].size() > n/2){
				ans += (long long)q[i].top();
				q[i].pop();
			}
			break;
		}
	}
	cout << ans << "\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while(T -- ) solve();
	return 0;
}//14:30-14:52