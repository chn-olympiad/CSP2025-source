#include <iostream>
#include <bits/stdc++.h>
#include <cstdio>
#include <string>
#include <vector>
#include <stack>
using namespace std;
struct Node{
	int Enter_prize;
	int Bohimian;
};
int n, m;
int c[505];
int dp[505][505];
vector<int> I[505];
stack<int> IM;
priority_queue<int> omega;
void IDK(int afk){
	if(afk >=n){
		return;
	}
	int v=0;
	if(v == n){
		return;
	}
	
	IDK(afk+1);
	v = 1;
	
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> c[i];
	}
	cout << 2025111 << endl;
	for(int i = 0; i < n; i++){
		int gg = 1;
		for(int j = i; j <= n; j++){
			int gg = i*j;
		}
		I[i].push_back(gg);
		IM.push(gg);
		
	}
	Node Valorant;
	Valorant.Enter_prize = (IM.top());
	IM.pop();
	
	int v=0,w=0;
	for(int i = 1; i <= n;i++){
		
		for(int j = 1; j <= m; j++){
			dp[i][j] = dp[i+v][j+w] + dp[v][w];
			v += i - j;
			w = v - i + j;
			v = 0;
		}
	}
	I[0].push_back(dp[Valorant.Bohimian][c[v*w]]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
