#include<bits/stdc++.h>
using namespace std;
#define LIMIT 998244353
unsigned short n,m,p;
unsigned short tp;
bool can[501];
short pra[501];
string tcan;
vector<unsigned short> patience;
unsigned long long ans = 0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin >> n >> m;
	cin >> tcan;
	for(int i=1;i<=n;i++){
		can[i] = (tcan[i-1] == '0');
	}
	
	for(int i=1;i<=n;i++){
		cin >> tp;
		if(tp > 0){
			patience.push_back(tp);
		}
	}
	p = patience.size();
	
	partial_sum(can,can+501,pra);
	
	short most = n-pra[501];
	if(most < m){
		cout << 0;
		return 0;
	}
	if(pra[501] == 0){
		ans = 1;
		while(p > 0){
			ans *= p;
			ans %= LIMIT;
			p--;
		}
		cout << ans << endl;
	}
	
	
	return 0;
}