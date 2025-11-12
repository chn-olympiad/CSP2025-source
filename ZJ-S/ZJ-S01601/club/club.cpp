#include<bits/stdc++.h>
using namespace std;
struct numbe{
	int lo , nu;
}num[100010][5];
int T , n , upp;
int cnty[5];
long long ans = 0;
priority_queue<int , vector<int> , greater<int> > q;
bool cmp1(numbe x , numbe y){
	return x.nu > y.nu;
}
int main(){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	cin >> T;
	while(T--){
		memset(cnty , 0 , sizeof(cnty));
		ans = 0;
		while(!q.empty()) q.pop();
		scanf("%d" , &n);
		upp = n >> 1;
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= 3 ; j++){
				num[i][j].lo = j;
				scanf("%d" , &num[i][j].nu);
			}
			sort(num[i] + 1 , num[i] + 4 , cmp1);
			ans += num[i][1].nu;
			cnty[num[i][1].lo]++;
		}
		int flag;
		for(int i = 1 ; i <= 3 ; i++){
			if(cnty[i] > upp) flag = i;
		}
		for(int i = 1 ; i <= n ; i++){
			if(num[i][1].lo == flag){
				q.push(num[i][1].nu - num[i][2].nu);
			}
		}
		while(cnty[flag] > upp){
			ans -= q.top();
			cnty[flag]--;
			q.pop();
		}
		printf("%d\n" , ans);
	}
	return 0;
}
