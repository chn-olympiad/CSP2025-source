#include<bits/stdc++.h>
using namespace std;
int t,a[100010][5] ={},sum1[5] = {},n;
int dfs(int deep,int sum,int up){
	if(deep > up){
		return sum;
	}
	int mx = -114514;
	for(int i = 1;i <= 3;i++){
		if(sum1[i] < n / 2){
			sum1[i]++;
			int ans = dfs(deep + 1, sum + a[deep][i], up);
			if(mx < ans){
				mx = ans;
			}
			sum1[i]--;
		}
	}
	return mx;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int ii = 1;ii <= t;ii++){
		sum1[1] = 0,sum1[2] = 0,sum1[3] = 0;
		cin >> n;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= 3;j++){
				a[i][j] = 0;
				cin >> a[i][j];
			}
		}
		printf("%d\n",dfs(1,0,n));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//3 4   4 2 1 3 2 4 5 3 4 3 5 1   4 0 1 0 0 1 0 0 2 0 0 2 0   2 10 9 8 4 0 0
