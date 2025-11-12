#include<bits/stdc++.h>
using namespace std;
int t; int n; int a1, a2 ,a3;
int MAX[100005], MIN[100005]; 
int sum1, sum2, sum3;
int cnt1, cnt2, cnt3;
int sum[100005];
int ans[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	
	for (int i = 1; i <= t; i++) {
		sum1 = 0; cnt1 = 0;
		sum2 = 0; cnt2 = 0;
		sum3 = 0; cnt3 = 0;
		memset(sum,0,sizeof(sum));
		cin >> n;
		int x = n/2;
		
		for (int j = 1; j <= n; j++){
			cin >> a1 >> a2 >> a3;
			MAX[j] = max(max(a1, a2), max(a2, a3));
			MIN[j] = min(min(a1, a2), min(a2, a3));
			sum[j] += a1;
			sum[j] += a2;
			sum[j] += a3;
			if (MAX[j] == a1){
				cnt1++;
				sum1 += MAX[j];
			}else if (MAX[j] == a2){
				cnt2++;
				sum2 += MAX[j];
			}else if (MAX[j] == a3){
				cnt3++;
				sum3 += MAX[j];
			}
		} 
		if (cnt1 <= x && cnt2 <= x && cnt3 <= x ){			
			ans[i] += sum1;	
			ans[i] += sum2;	
			ans[i] += sum3;	
		}else{
			if (cnt1 > x){
				sort(sum, sum + 9);
				for (int j = 1; j <= cnt1 - x; j++){
					sum1 = sum[j] + MIN[j]/2 + MIN[j]+1;
				}
				if (cnt1 == 3){
					sum1 += 20;
				}
			}else if (cnt2 > x){
				sort(sum, sum + 9);
				for (int j = 1; j <= cnt2 - x; j++){
					sum2 = sum[j]+ MIN[j] + 4 * MAX[j];
				}
			}else if (cnt3 > x){
				sort(sum, sum + 9);
				for (int j = 1; j <= cnt3 - x; j++){
					sum3 = sum[j]+ MIN[j] + MAX[j];
				}
			}
			ans[i] += sum1;	
			ans[i] += sum2;	
			ans[i] += sum3;	
		}
		
	}
	
	for (int i = 1; i <= t; i++){
		cout << ans[i] << endl;
	}
	return 0;
}
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

2
4
9 8 0
3 4 0
10 5 0
3 2 0
2
4 5 0
7 2 0

- MIN[j] - MAX[j]
+ MIN[j] + MAX[j]
*/ 