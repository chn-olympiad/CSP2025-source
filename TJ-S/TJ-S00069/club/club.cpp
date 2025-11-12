#include <iostream>
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int t;
int n;
int h[100005][4];
int vis[100005];
int ans;
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
void dfs(int p,int a,int b, int c, int cf){
	
	if(a+b+c> n){
		
		return;
		
	}
	if(a> n/2 || b > n/2 || c > n/2){
		return;
	}
	//cout << a << " " << b << " " << c << " " << cf << endl;
	if(ans < cf){
			ans = cf;
		}
	for(int j = p; j <= n; j++){
		if(vis[j] == 1){
			continue;
		}
		vis[j] = 1;
		
		
		dfs(p+1,a+1,b,c,cf+h[j][1]);
		dfs(p+1,a,b+1,c,cf+h[j][2]);
		dfs(p+1,a,b,c+1,cf+h[j][3]);
		
		/*for(int i = 1;i <=3;i++){
			
			
			if(i==1){
				
			} else if(i==2){
				
			}else if(i==3){
				
			}
		}*/
		
		vis[j] = 0;
	}
	
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int o = 0; o < t; o++){
		cin >> n;
		ans = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= 3; j++){
				cin >> h[i][j];
				
			}
		}
		dfs(1,0,0,0,0);
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
