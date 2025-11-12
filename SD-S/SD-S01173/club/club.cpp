#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

const int N = 100010;

int T;
int n,ren;
int a[N],b[N],c[N];
int ma[N]; // 每个人满意度最大的项目 不知道干啥用
int sum[5]; // 统计当取最大值时 每个项目的最值 
int club[5]; // 统计人数是否超过n/2 
int dp[3][N];
int tt[3][N];

struct Node {
	int e,f;
}chao[N];

bool cmp(Node x,Node y){
	if(x.e == y.e) return x.f > y.f;
	return x.e > y.e;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin >> T;
	while(T --){
		memset(ma,0,sizeof ma);
		memset(sum,0,sizeof sum);
		memset(club,0,sizeof club); 
		memset(dp,0,sizeof dp);
		memset(tt,0,sizeof tt);
		cin >> n;
		ren = n >> 1;
		for(int i = 1; i <= n; i ++){
			cin >> a[i] >> b[i] >> c[i];
			if(a[i] >= b[i] && a[i] >= c[i]){
//				cout << 1 << ' ';
				ma[i] = 1;
				club[1] ++;
				sum[1] += a[i];
			}else if(b[i] > a[i] && b[i] >= c[i]){
//				cout << 2 << ' ';
				ma[i] = 2;
				club[2] ++;
				sum[2] += b[i];
			}else{
//				cout << 3 << ' ';
				ma[i] = 3;
				club[3] ++;
				sum[3] += c[i];
			}
		}
		
		LL ans = 0;
		int flag = 0;
		for(int i = 1; i <= 3; i ++){
//			cout << sum[i] << ' ';
			if(club[i] > ren){
				flag = i;
			}else{
				ans += sum[i];
			}
		}
//		cout << ans << endl;
		
		if(flag != 0){
		/*
			第flag组超出人数，需要统计满意度前n>>2个人
			其余直接取次大值 
		*/
			for(int i = 1,j = 1; i <= n; i ++){
			 	if(ma[i] == flag){
			 		int x;
			 		if(flag == 1){
			 			x = max(b[i],c[i]);
			 			chao[j] = {a[i],x};
					}else if(flag == 2){
						x = max(a[i],c[i]);
						chao[j] = {b[i],x};
					}else{
						x = max(a[i],b[i]);
						chao[j] = {c[i],x};
					}
			 		
			 		j ++;
				 }
			 }
			 
			sort(chao + 1,chao + club[flag] + 1,cmp);
			
			for(int i = 1; i <= club[flag]; i ++){
				int a1 = dp[1][i - 1],a2 = dp[2][i - 1];
				int b1 = chao[i].e,b2 = chao[i].f;
				if(tt[1][i - 1] < ren){
					dp[1][i] = a1 + b1;
					tt[1][i] = tt[1][i - 1] + 1;
					dp[2][i] = a1 + b2;
					tt[2][i] = tt[1][i - 1];
				}else{
					dp[1][i] = dp[1][i - 1];
					tt[1][i] = tt[1][i - 1];
					dp[2][i] = dp[2][i - 1];
					tt[2][i] = tt[1][i - 1];
				}
				if(tt[2][i - 1] < ren){
					if(dp[1][i] < a2 + b1){
						dp[1][i] = a2 + b1;
						tt[1][i] = tt[2][i - 1] + 1;
					}
					if(dp[2][i] < a2 + b2){
						dp[2][i] = a2 + b2;
						tt[2][i] = tt[2][i - 1];
					}
					
				}
				
//				cout << dp[1][i] << ' ' << dp[2][i] << endl;
	} 
		}
//		cout << dp[1][n] << ' ' << dp[2][n] << ' ';
		cout << ans + max(dp[1][club[flag]],dp[2][club[flag]])<< endl;
	} 
	return 0;
}
