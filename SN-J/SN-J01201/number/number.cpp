#include<bits/stdc++.h> 
using namespace std;
string slo = "";
short alo[1005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> slo;
	int nlo = slo.size();
	slo = " "+slo;
	for(int ir = 1;ir <= nlo;ir++) if(slo[ir] <= '9'&& slo[ir] >= '0') alo[slo[ir]-'0']++;
	for(int ir = 9;ir >= 0;ir--) for(int jv = 1;jv <= alo[ir];jv++) cout << ir;
	return 0;
}
