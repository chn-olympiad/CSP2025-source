#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5e5;
vector <long long> mis[maxn];
vector <long long> a;
long long n, k, ans;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	a.resize(n);
	for(int i = 0; i < n; i++){
		int cmd;
		cin >> cmd;
		if(i == 0){
			a[i] = cmd;
		}
		else{
			a[i] = a[i-1] ^ cmd; 
		}
		mis[a[i]].push_back(i);
	}
	int last = n;
	for(int i = n-1; i >= 0; i--){
		if(!mis[a[i] ^ k].empty()){
			for(int j = 0; j < mis[a[i] ^ k].size(); j++){
				if(mis[a[i] ^ k][j] < last && mis[a[i] ^ k][j] > i){
					ans++;
					last = mis[a[i] ^ k][j];
				}
			}
		}
	}
	for(int i = 0; i < last; i++){
		if(a[i] == k){
			ans++;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
