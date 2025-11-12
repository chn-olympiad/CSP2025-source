#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>

typedef long long Int;
using namespace std;

std::map<std::pair<string, string>, int> MPA;

int main(){
	ifstream Q;
	Q.open("replace.in", istream::in);
	Int M, N, Ans;
	string P;
	Q >> N >> M;
	for(Int i = 0;i < N;i ++){
		string MP, MP1;
		Q >> MP >> MP1;
		MPA[{MP, MP1}] = true;
	}
		
	ofstream O;
	O.open("replace.out", ostream::out);
		
	for(Int i = 0;i < M;i ++){
		string QU[2];
		Ans = 0;
		Q >> QU[0] >> QU[1]; 
		
		Int Left = 0, Right = 0;
		for(Int j = 0;j < QU[0].size();j ++)
			if(QU[0][j] != QU[1][j]){
				j --;
				Left = j;
				break;
			}
		for(Int j = QU[0].size() - 1;j >= 0;j --)
			if(QU[0][j] != QU[1][j]){
				j ++;
				Right = j;
				break;
			}
		string LS = "", RS = "";
		for(Int j = Left + 1;j < Right;j ++){
			LS += QU[0][j];
			RS += QU[1][j];
		}
		string P = "";
		for(Int L = Left + 1;L >= 0;L --){
			if(L != Left + 1)
			P = QU[0][L] + P;
			string Q = "";
			for(Int R = Right - 1; R < QU[0].size();R ++){
				if(R != Right - 1)
				Q = Q + QU[0][R];
				Ans += MPA[{P + LS + Q, P + RS + Q}];
			}
		}
		O << Ans << "\n";
	}
	O.close();
	return 0;
}