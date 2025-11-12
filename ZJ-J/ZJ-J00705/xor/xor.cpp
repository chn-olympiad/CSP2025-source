#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
typedef long long Int;

const Int M = 500000;

Int Count = 0, K = 0, HC = 0, Ans = 0;
std::map<Int, std::pair<Int, bool> > O;
std::vector<Int> QU;
std::vector<std::pair<Int, Int> > Chose;

bool cmp(std::pair<Int, Int> A, std::pair<Int, Int> B){
	return A.second < B.second;
}

int main(){
	ifstream Open;
	ofstream Wr;
	Wr.open("xor.out", ostream::out);
	Open.open("xor.in", istream::in);
	Open >> Count >> K;
	O[0].first = 0;
	O[0].second = true;
	for(Int i = 1;i <= Count;i ++){
		Int U = 0;
		Open >> U;
		HC ^= U;
		if(O[HC ^ K].second)
			Chose.push_back({O[HC ^ K].first, i});
		O[HC].second = true;
		O[HC].first = i;
	}
	std::sort(Chose.begin(), Chose.end());
	Int Last = -1;
	for(Int i = 0;i < Chose.size();i ++){
		if(Last <= Chose[i].first)
			Last = Chose[i].second, Ans ++;
	}
	Wr << Ans;
	Wr.close();
	Open.close();
	return 0;
}
