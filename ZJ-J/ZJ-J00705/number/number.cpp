#include <iostream>
#include <fstream>
#include <ios>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long Int;

vector<Int> P;
string Q = "";

int main(){
	ifstream Open;
	Open.open("number.in", istream::in);
	ofstream O1pen;
	O1pen.open("number.out", ostream::out);
	
	Open >> Q;
	P.reserve(int(Q.size()));
	for(Int i = 0;i < int(Q.size());i ++)
		if('0' <= Q[i] && Q[i] <= '9')
			P.push_back(Q[i] - '0');
	sort(P.begin(), P.end());
	bool Out = false;
	for(Int i = P.size() - 1;i >= 0;i --){
		if(P[i]) Out = true;
		if(Out) O1pen << P[i];
	}
	if(!Out) O1pen << 0;
	
	Open.close();
	O1pen.close();
	return 0;
}
