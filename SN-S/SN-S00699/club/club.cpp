#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[100005][5],sum,x,y,z,vis[100005];
priority_queue<pair<int,int>> q1,q2,q3,q4,q5,q6;
//q1:1~2   q2:1~3   q3:2~1   q4:2~3   q5:3~1   q6:3~2
void clear(){
	while(q1.size()) q1.pop();
	while(q2.size()) q2.pop();
	while(q3.size()) q3.pop();
	while(q4.size()) q4.pop();
	while(q5.size()) q5.pop();
	while(q6.size()) q6.pop();
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--){
		sum = x = y = z = 0;
		memset(vis,0,sizeof(vis));
		clear();
		cin >> n;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= 3;j++){
				cin >> a[i][j];
			}
		}
		for(int i = 1;i <= n;i++){
			while(q1.size() && vis[q1.top().second] != 1) q1.pop();
			while(q2.size() && vis[q2.top().second] != 1) q2.pop();
			while(q3.size() && vis[q3.top().second] != 2) q3.pop();
			while(q4.size() && vis[q4.top().second] != 2) q4.pop();
			while(q5.size() && vis[q5.top().second] != 3) q5.pop();
			while(q6.size() && vis[q6.top().second] != 3) q6.pop();
			if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3]){
				vis[i] = 1;
				x++;
				q1.push({a[i][2] - a[i][1],i});
				q2.push({a[i][3] - a[i][1],i});
				if(x > n / 2){
					if(q1.top().first > q2.top().first){
						vis[q1.top().second] = 2;
						x--,y++;
						q1.pop();
					}
					else{
						vis[q2.top().second] = 3;
						x--,z++;
						q2.pop();
					}
				}
			}
			else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3]){
				vis[i] = 2;
				y++;
				q3.push({a[i][1] - a[i][2],i});
				q4.push({a[i][3] - a[i][2],i});
				if(y > n / 2){
					if(q3.top().first > q4.top().first){
						vis[q3.top().second] = 1;
						y--,x++;
						q3.pop();
					}
					else{
						vis[q4.top().second] = 3;
						y--,z++;
						q4.pop();
					}
				}
			}
			else{
				vis[i] = 3;
				z++;
				q5.push({a[i][1] - a[i][3],i});
				q6.push({a[i][2] - a[i][3],i});
				if(z > n / 2){
					if(q5.top().first > q6.top().first){
						vis[q5.top().second] = 1;
						z--,x++;
						q5.pop();
					}
					else{
						vis[q6.top().second] = 2;
						z--,y++;
						q6.pop();
					}
				}
			}
		}
		for(int i = 1;i <= n;i++){
			sum += a[i][vis[i]];
		}
		cout << sum << endl;
	}
	return 0;
}
