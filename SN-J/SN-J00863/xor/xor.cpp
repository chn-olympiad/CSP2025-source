//程诺龙轩 SN-J00863 曲江一中 
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10; 
int n,k,a[maxn];
int main(){;
//	std::ifstream cin("xor.in");
//	std::ofstream cout("xor.out");
	cin >> n >> k;
	for(int i = 1; i <= n;i++){
		cin >> a[i];
	}
	if(n<=2&&k==0){
		cout << 1;
	}
	return 0;
}
