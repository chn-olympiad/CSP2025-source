#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int T , n , stu[N][4] , stu1[N] , num[4] , twcnt[4] , rk[N][4] , ans , flag2 , flag3;
struct tuiwei{
	int id;
	int discount;
	int to_flag;
	friend bool operator< (const tuiwei &p , const tuiwei &q){
		return p.discount < q.discount;
	}
}tw[4][N];
void dfs(int now , int val){
	if(num[1] > n / 2 || num[2] > n / 2 || num[3] > n / 2){
		return;
	}
	if(now > n){
		ans = max(ans , val);
		return;
	}
	for(int i = 1;i <= 3;i++){
		num[i]++;
		dfs(now + 1 , val + stu[now][i]);
		num[i]--;
	}
}
int main(){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout); 
	cin>>T;
	while(T--){
		ans = 0;
		num[1] = num[2] = num[3] = 0;
		twcnt[1] = twcnt[2] = twcnt[3] = 0;
		cin>>n;
		for(int i = 1;i <= n;i++){
			cin>>stu[i][1]>>stu[i][2]>>stu[i][3];
			if(stu[i][2] > 0){
				flag2 = 1;
			}
			if(stu[i][3] > 0){
				flag3 = 1;
			}
			stu1[i] = stu[i][1];
		}
		if(n <= 10){
			dfs(1 , 0);
		}else if(!flag2 && !flag3){
			sort(stu1 + 1 , stu1 + n + 1);
			reverse(stu1 + 1 , stu1 + n + 1);
			for(int i = 1;i <= n / 2;i++){
				ans += stu1[i];
			}
		}else{
			for(int i = 1;i <= n;i++){
				if(stu[i][1] > stu[i][2]){
					if(stu[i][2] > stu[i][3]){
						//a > b > c
						rk[i][1] = 1;
						rk[i][2] = 2;
						rk[i][3] = 3;
					}else{
						if(stu[i][1] > stu[i][3]){
							//a > c > b
							rk[i][1] = 1;
							rk[i][2] = 3;
							rk[i][3] = 2;
						}else{
							//c > a > b
							rk[i][1] = 3;
							rk[i][2] = 1;
							rk[i][3] = 2;
						}
					}
				}else{
					if(stu[i][2] < stu[i][3]){
						//c > b > a
						rk[i][1] = 3;
						rk[i][2] = 2;
						rk[i][3] = 1;
					}else{
						if(stu[i][1] > stu[i][3]){
							//b > a > c
							rk[i][1] = 2;
							rk[i][2] = 1;
							rk[i][3] = 3;
						}else{
							//b > c > a
							rk[i][1] = 2;
							rk[i][2] = 3;
							rk[i][3] = 1;
						}
					}
				}
			}
			for(int i = 1;i <= n;i++){
				ans += stu[i][rk[i][1]];
				num[rk[i][1]]++;
				tw[rk[i][1]][twcnt[rk[i][1]]].id = i;
				tw[rk[i][1]][twcnt[rk[i][1]]].discount = stu[i][rk[i][1]] - stu[i][rk[i][2]];
				tw[rk[i][1]][twcnt[rk[i][1]]].to_flag = 2;
				if(num[rk[i][1]] > n / 2){
					sort(tw[rk[i][1]] + 1 , tw[rk[i][1]] + twcnt[rk[i][1]] + 1);
					ans -= tw[rk[i][1]][twcnt[rk[i][1]]].discount;
					tw[tw[rk[i][1]][twcnt[rk[i][1]]].to_flag][twcnt[tw[rk[i][1]][twcnt[rk[i][1]]].id]].id = tw[rk[i][1]][twcnt[rk[i][1]]].id;
					tw[tw[rk[i][1]][twcnt[rk[i][1]]].to_flag][twcnt[tw[rk[i][1]][twcnt[rk[i][1]]].id]].discount = stu[tw[tw[rk[i][1]][twcnt[rk[i][1]]].to_flag][twcnt[tw[rk[i][1]][twcnt[rk[i][1]]].id]].id][tw[rk[i][1]][twcnt[rk[i][1]]].to_flag] - stu[tw[tw[rk[i][1]][twcnt[rk[i][1]]].to_flag][twcnt[tw[rk[i][1]][twcnt[rk[i][1]]].id]].id][tw[rk[i][1]][twcnt[rk[i][1]]].to_flag + 1];
					tw[tw[rk[i][1]][twcnt[rk[i][1]]].to_flag][twcnt[tw[rk[i][1]][twcnt[rk[i][1]]].id]].to_flag = tw[rk[i][1]][twcnt[rk[i][1]]].to_flag + 1;
					if(tw[tw[rk[i][1]][twcnt[rk[i][1]]].to_flag][twcnt[tw[rk[i][1]][twcnt[rk[i][1]]].id]].to_flag > 3){
						tw[tw[rk[i][1]][twcnt[rk[i][1]]].to_flag][twcnt[tw[rk[i][1]][twcnt[rk[i][1]]].id]].discount = 999999999;
					}
					num[rk[i][1]]--;
					num[rk[twcnt[rk[i][1]]][tw[rk[i][1]][twcnt[rk[i][1]]].to_flag]]--;
				}
			}
		}
		cout<<ans<<'\n';
	}
}
