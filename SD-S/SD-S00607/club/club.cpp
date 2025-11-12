#include<bits/stdc++.h>
using namespace std;
int T , n;
int vis[5]; 
int sum[5];
struct node{
	int a , b , c;
	int m1 , m2, m3;
	int v1 , v2 , v3;
}t[100005];
priority_queue<pair<int , int> , vector<pair<int , int> > , greater<pair<int , int> > > q[4];
void init(int x) {
	pair<int , int> reg[5];
	reg[1].first = t[x].a , reg[1].second = 1;
	reg[2].first = t[x].b , reg[2].second = 2;
	reg[3].first = t[x].c , reg[3].second = 3;
	sort(reg + 1 , reg + 4);
	t[x].m1 = reg[3].second , t[x].m2 = reg[2].second , t[x].m3 = reg[1].second;
	t[x].v1 = reg[3].first , t[x].v2 = reg[2].first , t[x].v3 = reg[1].first;
} 
int main() {
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	cin >> T;
	while(T--) {
		memset(sum , 0 , sizeof sum);
		memset(vis , 0 , sizeof vis);
		for(int i = 1 ; i <= 3 ; i++) {
			while(!q[i].empty()) {
				q[i].pop(); 
			}
		}
		cin >> n;
		for(int i = 1 ; i <= n ; i++) {
			cin >> t[i].a >> t[i].b >> t[i].c;
			init(i);
		}
		for(int i = 1 ; i <= n ; i++) {
			if(vis[t[i].m1] == n / 2) {
				if(t[i].v1 + sum[t[i].m1] - q[t[i].m1].top().first > sum[t[i].m1] + t[i].v2) {
					sum[t[i].m1] += t[i].v1 - t[q[t[i].m1].top().second].v1;
					sum[t[q[t[i].m1].top().second].m2] += t[q[t[i].m1].top().second].v2;
					vis[t[q[t[i].m1].top().second].m2] ++;
					q[t[i].m1].pop();
					q[t[i].m1].push({t[i].v1 - t[i].v2 , i});
				}else{
					sum[t[i].m2] += t[i].v2;
					vis[t[i].m2] ++;
					q[t[i].m2].push({t[i].v2 - t[i].v1 , i});
				}
			}else{
				q[t[i].m1].push({t[i].v1 - t[i].v2 , i});
				sum[t[i].m1] += t[i].v1;
				vis[t[i].m1] ++;
			}
		}
		cout << sum[1] + sum[2] + sum[3] << "\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
