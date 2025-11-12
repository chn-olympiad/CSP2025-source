#include<bits/stdc++.h>
using namespace std;
int num1 = 0 , num2 = 0 , num3 = 0 , ans = 0;
int main(){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	int n , q;cin >> q;
	while(q--){
		int x[100005][3];
		vector<int> l1 , l2 , l3;
		cin >> n;
		for(int i = 1;i <= n;i++) cin >> x[i][0] >> x[i][1] >> x[i][2];
		int maxn = n / 2;
		for(int i = 1;i <= n;i++) {
			if(x[i][0] > x[i][1] && x[i][0] > x[i][2]){ans += x[i][0]; num1++;l1.push_back(i);} 
			if(x[i][1] > x[i][0] && x[i][1] > x[i][2]){ans += x[i][1]; num2++;l2.push_back(i);} 
			if(x[i][2] > x[i][1] && x[i][2] > x[i][0]){ans += x[i][2]; num3++;l3.push_back(i);}
		}
		if(num1 > maxn){
			for(int i = 0;i < num1 - maxn;i++){
				int max1 = -20000 , max2 = -20000;
				for(auto t : l1) max1 = max(max1 , x[t][1] - x[t][0]);
				for(auto t : l1) max2 = max(max2 , x[t][2] - x[t][0]);
				ans += max(max1 , max2);
			}
			
		}
		if(num2 > maxn){
			for(int i = 0;i < num2 - maxn;i++){
				int max1 = -20000 , max2 = -20000;
				for(auto t : l2) max1 = max(max1 , x[t][0] - x[t][1]);
				for(auto t : l2) max2 = max(max2 , x[t][2] - x[t][1]);
				ans += max(max1 , max2);
			}
			
		}
		if(num3 > maxn){
			for(int i = 0;i < num3 - maxn;i++){
				int max1 = -20000 , max2 = -20000;
				for(auto t : l3) max1 = max(max1 , x[t][0] - x[t][2]);
				for(auto t : l3) max2 = max(max2 , x[t][1] - x[t][2]);
				ans += max(max1 , max2);
			}
			
		}
		cout << ans << "\n";
		ans = 0;
		num1 = num2 = num3 = 0;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}