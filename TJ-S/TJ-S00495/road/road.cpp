#include<bits/stdc++.h>
using namespace std;

const int CITYN = 1e4+10;
const int ROADN = 1e6+10;
const int TOWNN = 10+2;

int cityn, roadn, townn;
int roads[CITYN][CITYN];
int dp[CITYN];

int Solve(){
	
	return 0;
}

int main(){
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	cin >> cityn >> roadn >> townn;
	memset(roads, 0x7f, sizeof(roads));
	for(int i = 1; i <= roadn; i ++){
		int tar1, tar2, cost;
		cin >> tar1 >> tar2 >> cost;
		roads[tar1][tar2] = cost;
		roads[tar2][tar1] = cost;
	}
	int tmp;
	for(int i = 1; i <= townn; i ++){
		cin >> tmp;
		for(int j = 1; j <= cityn; j ++){
			cin >> tmp;
		}
	}
	cout << Solve();
	return 0;
}
/*
const int MAX = INT_MAX;
const int CITYN = 1e4+10;
const int ROADN = 1e6+10;
const int TOWNN = 10+2;

struct Road{
	int tar1, tar2;
	int cost;
};

int cityn, roadn, townn;
int towninit[TOWNN];
vector<vector<int> > townto(0);
vector<Road> roads(1,(Road){-1,-1,MAX});
int dp[CITYN][CITYN][1<<TOWNN];

bool HasTown(int townbit, int idx){
	return townbit & (1<<(idx-1));
}

int Solve(){
	int ans = MAX;
	
	return ans;
}

int main(){
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	cin >> cityn >> roadn >> townn;
	townto = vector<vector<int> >(townn+1,vector<int>(1,MAX));
	for(int i = 1; i <= roadn; i ++){
		int tar1, tar2, cost;
		cin >> tar1 >> tar2 >> cost;
		roads.push_back((Road){tar1,tar2,cost});
	}
	for(int i = 1; i <= townn; i ++){
		cin >> towninit[i];
		for(int j = 1; j <= cityn; j ++){
			int tmp;
			cin >> tmp;
			townto[i].push_back(tmp);
		}
	}
	cout << Solve();
	return 0;
}
*/
