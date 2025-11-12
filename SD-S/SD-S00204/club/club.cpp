#include<bits/stdc++.h>
using namespace std;
int arr[100001][4];
int sum, maxpo;
bool used[100001][4];
bool num(int n){//计数，统计 第几个社团是否超过n/2 
	for (int j = 1; j <= 3; j++){
		int num1 = 0;
		for (int i = 1; i <= n; i++){
			num1 += used[i][j];//统计选中j社团的人数 
//			cout << num1 << "[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]" << endl;
			if (num1 > (n/2)){
				return true;
			}
		}	
	}
	return false;
}

bool finishy(int n){//计数，统计 是否全部枚举 
	for (int i = 1; i <= n; i++){
		if (!used[i][3]){
			return false;
		}
	}
	return true;
}
void sigma(int cnt, int n, int com){//第几人，人数，第几个社团 
//	cout << arr[cnt][com] << endl;
	used[cnt][com] = true;//选择社团 
	sum += arr[cnt][com];
	
//求期望和
//	cout << sum << "***" << endl;
	if (cnt > (n/2)){//超出n/2人自动排除
		if(num(n)){
			return;//回退 
		}
	}
	if (cnt == n){//第n个人 
		maxpo = max(maxpo, sum);
//		cout << maxpo << "--------------" << endl;
		return; 
	}
	for (int i = com; i <= com + 2; i++){
		sigma(cnt+1, n, i);//下一个人去第i个社团 
		used[cnt+1][i] = false;
		sum -= arr[cnt+1][i];//回退 
//		cout << sum << "和" << endl;
	}
	if (cnt == n && com == 3){
		if (finishy(n)){//所有情况全部枚举 
			return;
		}
	}
	used[cnt][com] = false;
	sum -= arr[cnt][com];//回退 
	return;
}

int main(){
	freopen("club.in", "r", stdin);//注意更改 
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++){
		int n;
		cin >> n;
		for (int j = 1; j <= n; j++){
			for (int k = 1; k <= 3; k++){
				cin >> arr[j][k];
			}
		}
		int maxps = maxpo;
		for (int l = 1; l <= 3; l++){
			sigma(1, n, l);
			sum = 0;
			maxps = max(maxps, maxpo);//得到的3个最大值比较 
		}
		cout << maxps << endl;
		maxpo = 0;
	}
	return 0;
}


