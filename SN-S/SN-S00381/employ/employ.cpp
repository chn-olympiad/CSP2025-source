#include<bits/stdc++.h>
using namespace std;
int n,m;
int main (){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >>m;
	if (n==m){
		cout << 1;
		return 0;
	}
	long long a=n-1;
	for (int i=n-2;i>0;i--){
		a*=i;
	}
	cout << a;
	return 0;
}

