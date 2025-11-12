#include <bits/stdc++.h>
using namespace std;
int T;
int n;
int a[100005][4];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q[4];
queue<int> l;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--){
		int ans = 0;
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			l.push(i);
		}
		while(l.size()){
			int i = l.front();
			l.pop();
			if(a[i][1] > a[i][2]){
				if(q[1].size() < n/2) q[1].push({a[i][1],i});
				else if(q[1].top().first + a[i][2] < a[i][1] + a[q[1].top().second][2]){
					q[2].push({q[1].top().first,q[1].top().second});
					q[1].pop();
					q[1].push({a[i][1],i});
				}
				else q[2].push({a[i][2],i});
			}
			else{
				if(q[2].size() < n/2) q[2].push({a[i][2],i});
				else if(q[2].top().first + a[i][1] < a[i][2] + a[q[2].top().second][1]){
					q[1].push({q[2].top().first,q[2].top().second});
					q[2].pop();
					q[2].push({a[i][2],i});
				}
				else q[1].push({a[i][1],i});
			}
		}
		while(q[1].size()){
			ans += q[1].top().first;
			q[1].pop();
		}
		while(q[2].size()){
			ans += q[2].top().first;
			q[2].pop();
		}
		cout << ans << endl;
	}
}
