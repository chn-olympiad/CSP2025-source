#include<bits/stdc++.h>
using namespace std;

priority_queue<pair<long long,long long> ,vector<pair<long long,long long> > ,greater<pair<long long,long long> > > q1,q2,q3;
const long long N = 1e5+5;
long long i,j,k,l,n,m,a[N][5]; 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t --){
		cin >> n;
		a[0][1] = a[0][2] = a[0][3] = a[n+1][1] = a[n+1][2] = a[n+1][3] = 0;
		for(i = 1;i <= n;i ++){
			cin >> a[i][1]>> a[i][2]>> a[i][3];
		}
		
		for(i = 1;i <= n;i ++){
			if(a[i][1] >= a[i][2]&&a[i][1] >= a[i][3]){
				q1.push({min(a[i][1]-a[i][2] , a[i][1]-a[i][3]) , i});
			}
			else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3]){
				q2.push({min(a[i][2]-a[i][1] , a[i][2]-a[i][3]) , i});
			}else{
				q3.push({min(a[i][3]-a[i][2] , a[i][3]-a[i][1]) , i});
			}
		}
		if(q1.size() > n/2){
			
			while(q1.size() > n/2){
				long long x = q1.top().second;
				q1.pop();
				if(a[x][2] >= a[x][3]){
					q2.push({a[x][2] , x});
				}else{
					q3.push({a[x][3] , x});
				}
			}
			
		}else if(q2.size() > n/2){
			
			while(q2.size() > n/2){
				long long x = q2.top().second;
				q2.pop();
				if(a[x][1] >= a[x][3]){
					q1.push({a[x][1] , x});
				}else{
					q3.push({a[x][3] , x});
				}
			}
			
		}else if(q3.size() > n/2){
			
			while(q3.size() > n/2){
				long long x = q3.top().second;
				q3.pop();
				if(a[x][2] >= a[x][1]){
					q2.push({a[x][2] , x});
				}else{
					q1.push({a[x][1] , x});
				}
			}
		}
		long long ans = 0;
		while(q1.size()){
			ans += a[ q1.top().second ][1];
			q1.pop();
		}
		while(q2.size()){
			ans += a[ q2.top().second ][2];
			q2.pop() ;
		}
		while(q3.size()){
			ans += a[ q3.top().second ][3];
			q3.pop();
		}
		cout << ans<<'\n';
	}
	return 0;
}