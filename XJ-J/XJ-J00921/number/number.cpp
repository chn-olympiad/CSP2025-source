#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	string s;
	cin >> s;
	
	long long int n = s.size();
	char R[n];
	memset(R, 0, sizeof(R));
	for(int i=0;i<n;i++){
		if(s[i] <= '9'){
			R[i] = s[i];
		}
	}
	
	for(int i=0;i<sizeof(R);i++){
		for(int j=i;j<sizeof(R);j++)
			if(R[i] < R[j]) swap(R[i], R[j]);
	}
	
	for(int i=0;i<sizeof(R);i++) cout << R[i];
	
	return 0;
}
