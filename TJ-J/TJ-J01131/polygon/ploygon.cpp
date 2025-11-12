#include <bits/stdc++.h>

using namespace std;

int n,a,b,c;

int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin >> n >> a >> b >> c;
	if(a + b > c && abs(a - b) < c) cout << 1;
	return 0;
}

