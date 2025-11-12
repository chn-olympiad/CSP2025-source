#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long Int;

bool cmp(std::pair<Int, Int> A, std::pair<Int, Int> B){
	return A.first < B.first;
}

int main(){
	ifstream Open;
	Open.open("club.in", istream::in);
	ofstream Out;
	Out.open("club.out", ostream::out);
	
	Int T = 0;
	Open >> T;
	while(T --){
		vector<std::pair<Int, Int> > A, B, C;
		vector<vector<Int> > MS;
		Int M, Sum = 0;
		Open >> M;
		MS.resize(M, vector<Int>(3));
		for(Int i = 0;i < M;i ++){
			Open >> MS[i][0] >> MS[i][1] >> MS[i][2];
			if(MS[i][0] >= MS[i][1] && MS[i][0] >= MS[i][2]){
				A.push_back({MS[i][0], i}), Sum += MS[i][0];
			}else if(MS[i][1] >= MS[i][0] && MS[i][1] >= MS[i][2]){
				B.push_back({MS[i][1], i}), Sum += MS[i][1];
			}else C.push_back({MS[i][2], i}), Sum += MS[i][2];
		}
		if(A.size() > M/2){
			sort(A.begin(), A.end(), cmp);
			for(Int i = 0;i < A.size() - M / 2;i ++){
				Sum -= A[i].first;
				Sum += std::max(MS[A[i].second][1], MS[A[i].second][2]);
			}
		}else if(B.size() > M/2){
			sort(B.begin(), B.end(), cmp);
			for(Int i = 0;i < B.size() - M / 2;i ++){
				Sum -= B[i].first;
				Sum += std::max(MS[B[i].second][0], MS[B[i].second][2]);
			}
		}else if(C.size() > M/2){
			sort(C.begin(), C.end(), cmp);
			for(Int i = 0;i < C.size() - M / 2;i ++){
				Sum -= C[i].first;
				Sum += std::max(MS[C[i].second][1], MS[C[i].second][0]);
			}
		}
		Out << Sum << "\n";
	}
	
	Open.close();
	Out.close();
	return 0;
}