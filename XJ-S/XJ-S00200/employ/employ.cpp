#include<bits/stdc++.h>
using namespace std;
const int M = 998244353;
int n,m,fl = 0,sum = 0;
string s;
int c[505];
long long cheng(int x,int y){
	long long ans = 1;
	int pos1 = y,pos2 = x-y;
	if (pos1 < pos2) swap(pos1,pos2);
	for (int i = pos1+1;i <= x;i++){
		ans *= i;
	}
	for (int i = 1;i <= pos2;i++){
		ans /= i;
	}
	return ans % M;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1;i <= n;i++){
		cin >> c[i];
		if (c[i] == 0) fl = 1;
		if (c[i] == 1) sum++;
	}
	if (m == n){
		if (fl == 0){
			cout << 1;
		}else{
			cout << 0;
		}
		return 0;
	}
	cout << cheng(n,m);
	return 0;
}

