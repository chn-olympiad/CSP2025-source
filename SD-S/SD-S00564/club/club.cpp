#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int MAXN = 100050;
int renyi[MAXN][3];
int movement[MAXN];
// movement 的第 i 位存储的是 renyi 的第 i+1 组数据的长度。
int t;
int shuju[MAXN];


int user_input(){
	cin >> t;
	movement[0] = 0;
	for(int mm = 1; mm <= t; mm++){
		cin >> movement[mm];
		for(int i = 0; i < t; i++){
			for(int j = 0; j < 0x00000003; j++){
				cin >> renyi[i][j];
			}
		}
	}
	return 0;
}


int baoli(int st, int ed){
	// 暴力求解，左闭右开。
	int maxi = -INT_MAX, tmp;
	if(ed - st == 2){
		tmp = renyi[ed - 1][0] + renyi[st][1];
//		printf("tmp=%d\n", tmp);
		if(tmp > maxi) maxi = tmp;
		tmp = renyi[ed - 1][0] + renyi[st][2];
//		printf("tmp=%d, renyi[ed - 1][0]=%d, renyi[st][2]=%d\n", tmp, renyi[ed - 1][0], renyi[st][2]);
		if(tmp > maxi) maxi = tmp;
		tmp = renyi[ed - 1][1] + renyi[st][2];
//		printf("tmp=%d\n", tmp);
		if(tmp > maxi) maxi = tmp;
		tmp = renyi[ed - 1][1] + renyi[st][0];
//		printf("tmp=%d\n", tmp);
		if(tmp > maxi) maxi = tmp;
		tmp = renyi[ed - 1][2] + renyi[st][0];
//		printf("tmp=%d\n", tmp);
		if(tmp > maxi) maxi = tmp;
		tmp = renyi[ed - 1][2] + renyi[st][1];
		//printf("tmp=%d\n", tmp);
		if(tmp > maxi) maxi = tmp;
	} else {
		for(int i = st; i < ed; i++){
//			for(int i = 0; i < )
//			renyi[i][0]
		}
		maxi = 0;
	}
	return maxi;
}


int main(void){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	///////////////////////////////////////////////
	int ptr = 0;
	user_input();
	for(int i = 0; i < t; i++){
//		printf("ptr=%d, movement[i]=%d\n", ptr, movement[i]);
//		cout << baoli(ptr, ptr + movement[i]) << endl;
		ptr += movement[i];
	}
	///////////////////////////////////////////////
	fclose(stdin);
	fclose(stdout);
	return 0;
}

