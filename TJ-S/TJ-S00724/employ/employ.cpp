//Sling
//4-employ
//Passed_ex non
//Predict ac_point 2/25
#include<iostream>
using namespace std;

const long long Q = 998244353;
int n,m;
long long sol;
string s;
int e[510];

int main() //Solution to special characteristic A
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 1;i <= n;i++) cin >> e[i];
	sol = 1;
	for(int i = 2;i <= n;i++) {
		sol *= i;
		sol %= Q;
	}
	cout << sol << endl;
	return 0;
}
