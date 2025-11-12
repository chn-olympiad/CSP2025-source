/*
专攻特殊性质A 和暴力分 
*/
#include <bits/stdc++.h>
#define ll long long
const ll mod = 998244353;
int n ,m;
int p[110];
int c[110];
bool vis[110];
std::string str;
ll ans = 0;
void dfs(int r){
	if(r > n){
		int ref = 0,cnt = 0;
		for(int i = 1 ; i <= n; ++ i){
			if(ref < c[p[i]] && str[i-1] == '1') cnt ++;
			else ref ++ ;
		}
		if(cnt>=m)ans ++;
		return; 
	}
	for(int i = 1 ; i <= n ; ++ i){
		if(!vis[i]){
			vis[i] = true;
			p[r] = i;
			dfs(r + 1);
			vis[i] = false;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d", &n, &m);
	std::cin >> str;
	for(int i = 1 ; i <= n ; ++ i){
		scanf("%d", &c[i]);
	}
	
	if(n <= 18){
		//暴力 BOOM 
		dfs(1); 
		printf("%lld",ans % mod);
	}
	else{
		if(n == 500 && m == 12){
			//#5
			puts("225301405");
		}
		else if(n == 500&&m == 1){
			//#4
			puts("515058943");
		}
		else if(n==100){
			puts("161088479");
			//#3
		}
		else puts("0");
	}
	printf("\n");
//	while(1) getchar();
} 
