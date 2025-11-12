#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <fstream>

typedef long long Int;
using namespace std;

map<Int, map<Int, Int> > All;
std::vector<std::pair<std::pair<Int, Int>, Int>> Mp;

Int N, M, K, Ans = 0;

struct Un{
	Int Last = 0;
	Int N[10020] = {};
	
	void Init(){
		for(Int i = 0;i < 10020;i ++){
			N[i] = i;
		}return;
	}
	
	void Add(Int A, Int B){
		Int FA = Found(A), FB = Found(B);
		N[FA] = N[FB];
		return;
	}
	
	Int Found(Int A){
		Int Root = A;
		while(N[Root] != Root)
			Root = N[Root];
		N[A] = Root;
		return N[A];
	}
	
	bool isSame(Int A, Int B){
		return Found(A) == Found(B);
	}
};

bool cmp(std::pair<std::pair<Int, Int>, Int> A, std::pair<std::pair<Int, Int>, Int> B){
	return A.second < B.second;
}

Int MTree(){
	Un Mp1;
	Mp1.Init();
	sort(Mp.begin(), Mp.end(), cmp);
	for(Int i = 0;i < Mp.size();i ++){
		if(!Mp1.isSame(Mp[i].first.first, Mp[i].first.second)){
			Ans += Mp[i].second;
			Mp1.Add(Mp[i].first.first, Mp[i].first.second);
		}
	}
	return 0;
}

void GetMP(){
	for(Int i = 1;i < N;i ++)
		for(Int j = i + 1;j <= N;j ++)
			Mp.push_back({{i, j},All[i][j]});
}

int main(){
	ifstream In;
	In.open("road.in", istream::in);
	ofstream Out;
	Out.open("road.out", ostream::out);
	
	In >> N >> M >> K;
	for(Int i = 1;i <= M;i ++){
		Int Left = 0, Right = 0, Val = 0;
		In >> Left >> Right >> Val;
		All[std::min(Left, Right)][std::max(Left, Right)] = std::min(Val, (All[std::min(Left, Right)][std::max(Left, Right)] == 0 ? 10000000 : All[std::min(Left, Right)][std::max(Left, Right)]));
	}
	
	Int List[11][10010] = {};
	for(Int i = 0;i < K;i ++){
		for(Int j = 0;j <= N;j ++){
			In >> List[i][j];
		}
	}
	for(Int i = 0;i < K;i ++){
		for(Int j = 1;j < N;j ++){
			for(Int k = j + 1;k <= N;k ++){
				All[j][k] = std::min((All[j][k] == 0 ? 1000000 : All[j][k]), List[i][0] + List[i][j] + List[i][k]);
//				if(j == 1 && k == 4) cout << List[i][0] << " " << List[i][j] + List[i][k] << "\n";
			}
		}
	}
	GetMP();
	MTree();
	Out << Ans;
	In.close();
	Out.close();
	return 0;
}