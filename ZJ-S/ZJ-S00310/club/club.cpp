#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, M = 3;

int n;
long long a[N][M];

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	int T;
	cin >> T;
	while(T --){
		cin >> n;
	
		for(int i = 1; i <= n; i ++)
			for(int j = 0; j < M; j ++)
				scanf("%lld", &a[i][j]);
			
		priority_queue<long long, vector<long long>, greater<long long> > q[M];
		long long ans = 0;
		for(int i = 1; i <= n; i ++){
			long long maxx = 0, midd = 0, maxp = 0, midp = 0;
			for(int j = 0; j < M; j ++)
				if(a[i][j] >= maxx)
					midd = maxx, midp = maxp, maxx = a[i][j], maxp = j;
				else if(a[i][j] >= midd)
					midd = a[i][j], midp = j;
		
			long long k = maxx - midd;
			int sz = q[maxp].size();
			if(sz * 2 == n)
				if(q[maxp].top() <= k){
					ans = ans - q[maxp].top() + maxx;
					q[maxp].pop();
					q[maxp].push(k);
				}
				else
					ans += midd;
			else
				q[maxp].push(k), ans += maxx;
	
		}
	
		printf("%lld\n", ans);
	}
	

	return 0;
}