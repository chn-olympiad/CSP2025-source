#include<bits/stdc++.h>
using namespace std; 

int t, n; 
int a[100005][5]; 
vector <int> v[5]; 

int main(){
	freopen("club.in", "r", stdin); 
	freopen("club.out", "w", stdout);  
	
	scanf("%d", &t); 
	while(t--){
		v[1].clear(), v[2].clear(), v[3].clear(); 
		memset(a, 0, sizeof(a)); 
		scanf("%d", &n); 
		for(int i = 1; i <= n; i++) scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]); 
		int ans = 0; 
		
		
		for(int i = 1; i <= n; i++){
			int x = a[i][1], y = a[i][2], z = a[i][3]; 
			if(x >= y and x >= z) ans += x, v[1].push_back(i); 
			else if(y >= x and y >= z) ans += y, v[2].push_back(i); 
			else ans += z, v[3].push_back(i); 
		}	
		
		int cnt = 0, rdc[100005]; 
		for(int k = 1; k <= 3; k++){
			int l = v[k].size(); 
			if(l <= n / 2) continue; 
			
			for(int i = 0; i < l; i++){
				int t = a[v[k][i]][k], x = a[v[k][i]][1], y = a[v[k][i]][2], z = a[v[k][i]][3]; 
				int sub; 
				if(k == 1) sub = min(t - y, t - z); 
				if(k == 2) sub = min(t - x, t - z); 
				if(k == 3) sub = min(t - x, t - y); 
				rdc[cnt++] = sub; 
			}
			sort(rdc, rdc + l); 
			for(int i = 0; i < l - (n / 2); i++) ans -= rdc[i]; 
		}
		
		printf("%d\n", ans); 
	}
	
	return 0; 
} 

