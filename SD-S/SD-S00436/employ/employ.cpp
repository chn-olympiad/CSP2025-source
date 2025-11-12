#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fir first
#define sec second
#define endl '\n'
const int N=1e6+5,M=5e3+5;
const int P=998244353;

int n,m;
string s;
int c[N];

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m >> s;
	for(int i=1;i<=n;i++){
		cin >> c[i];
	}
	int res=1;
	for(int i=1;i<=n;i++){
		res*=i;
		res%=P;
	}
	cout << res << endl;
	return 0;
}






//*Some strong music rings...
/*
Today is 20251101.
The code is by XYM!!!
*/
//We are strange to love.
//You know the rules and so do I~
//
//Never gonna give you up.
//Never gonna let you down.
//Never gonna run around and hurt you.
//Never gonna make you cry.
//Never gonna say goodbye.
//Never gonna run around and hurt you.
//
//luogu UID 1433474,luogu name Meng_Xiangyu
//I AKed CSP-J this morning.

