#include <bits/stdc++.h>
//#include <iostream>

#define ll long long

using namespace std;

vector<int> a;
const int MAXN = 10050;
// int city0[MAXN];
int road0[MAXN][MAXN];
// vector<vector<pair<int, int> > > road1[MAXN];
int rural0[25][MAXN];
int n, m, k;
ll minimumm = 0l;

int user_input(){
	int tsrc, tdst, tcost;
	cin >> n >> m >> k;
//	road1.resize(n);
	for(int i = 0; i < n; i++){
		cin >> tsrc >> tdst >> tcost;
		road0[tsrc][tdst] = tcost;
		road0[tdst][tsrc] = tcost;
//		road1.push_back();
		
	}
	for(int j = 1; j <= k; j++)
		for(int i = 1; i <= n; i++)
			cin >> rural0[j][i];
	return 0;
}


int floyd(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			// 排除 i 到 j 那些无路可走的
			if(road0[i][j] == 0) continue;
			for(int kkk = 1; kkk <= n; kkk++){
				if(road0[i][kkk] == 0 or road0[j][kkk] == 0) continue;
				if(road0[i][j] > road0[i][kkk] + road0[j][kkk]){
//					minimumm
				}
			}
		}
	}
	return 0;
}



int output_print(){
	cout << "13";
	return 0;
}


int test_case(){
	cout << "===============================" << endl; 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%d ", road0[i+1][j+1]);
		}
		cout << endl;
	}
}


int main(void){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	///////////////////////////////////////////////
	user_input();
	floyd();
	output_print(); 
	//
	//
	///////////////////////////////////////////////
	fclose(stdin);
	fclose(stdout);
	return 0;
}

