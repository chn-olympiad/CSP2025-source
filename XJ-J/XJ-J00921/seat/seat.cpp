#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	int s[n * m];
	int f[n * m];
	for(int i=0;i<n*m;i++){
		cin >> s[i];
		f[i] = i + 1;
	}
	
	for(int i=0;i<n*m;i++){
		for(int j=i;j<n*m;j++){
			if(s[i] < s[j]){
				swap(s[i], s[j]);
				swap(f[i], f[j]);
			}
		}
	}
	
	int num = 0;
	for(int i=0;i<n*m;i++){
		if(f[i] == 1) num = i + 1;
	} 
	
	int l;
	if(num % n != 0){
		l = (num - 1) / n + 1;
		if(l % 2 == 0) cout << l << " " << (l * n - num) + 1; 
		else if(l % 2 != 0) cout << l << " " << num - (l - 1) * n;
	}
	else if(num % n == 0){
		l = num / n;
		if(l % 2 != 0) cout << l << " " << n;
		else if(l % 2 == 0) cout << l << " " << 1;
	}
	else if(num / n == m){
		if(l % 2 == 0) cout << m << " " << m;
		else if(l % 2 != 0) cout << m << " " << 1;
	} 
	
	return 0;
}
