#include<bits/stdc++.h>

#define int long long

#define maxn 200005

#define INF (int)(1e18)

#define double long double

using namespace std;

const int mod = 998244353;

int n,m;

char s[505];

int c[505];

int p[505];

signed main(){

	ios::sync_with_stdio(0);
	
	cin.tie(0);
	
	cout.tie(0);
	
	freopen("employ.in","r",stdin);
	
	freopen("employ.out","w",stdout);
	
	cin >> n >> m;
	
	for(int i = 1;i <= n;++ i) cin >> s[i];
	
	for(int i = 1;i <= n;++ i) cin >> c[i];
	
	if(n <= 10){
		
		for(int i = 1;i <= n;++ i) p[i] = i;
		
		int ans = 0;
		
		do{
			
			int now = 0,cnt = 0;
			
			for(int i = 1;i <= n;++ i){
				
				int x = p[i];
				
				if(now >= c[x]) ++ now;
				
				else {
					
					if(s[i] == '1') ++ cnt;
					
					else ++ now;
					
				}
				
			}
			
			if(cnt >= m) ++ ans;
			
		}while(next_permutation(p + 1,p + n + 1));
		
		cout << ans % mod << "\n";
		
		return 0;
		
	}
		
	return 0;

}

