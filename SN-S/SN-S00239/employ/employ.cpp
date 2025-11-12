#include "bits/stdc++.h"
using namespace std;
const int N = 505;
const long long M = 998244353;

int n, m;
long long ans = 1;
int s[N], c[N];
bool flag = 0;

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	string s;
	cin>>s;
	cout<<endl;
	for(int i=0;i<n;++i){
		if(s[i] == '0'){
			flag = 1;
			break;
		}
	}
	for(int i=1;i<=n;++i){
		cin>>c[i];
	}
	
	if(!flag){
		for(int i=1;i<=m;i++){
			ans = ans * n % M;
			n--;
		}
		cout<<ans<<endl;
		return 0;
	}
	
	return 0;
}
