#include <iostream>
#include <fstream>
#include <ios>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long Int;

Int H = 0, W = 0, Score = 0, BgCount = 0;
pair<Int, Int> Ans;

int main(){
	ifstream FD;
	FD.open("seat.in", istream::in);
	FD >> H >> W >> Score;
	for(Int i = 0;i < W * H - 1;i ++){
		Int HC = 0;
		FD >> HC;
		if(HC > Score) BgCount ++;
	}
	Ans.first = BgCount / H + 1;
	Ans.second = (Ans.first % 2 == 1 ? BgCount % H + 1 : H - BgCount % H);
	ofstream FD1;
	FD1.open("seat.out", ostream::out);
	FD1 << Ans.first << " " << Ans.second;
	FD1.close();
	FD.close();
	return 0;
}
