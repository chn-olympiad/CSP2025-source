#include<bits/stdc++.h>
using namespace std;
int a[114514];
int main(){
	freopen("seat.in","r","stdin");
	freout("seat.out","w","stdout");
	int n, m;
	cin >> n >> m;
	for (int i=1; i<= n*m; i++){
		cin >> a[i];
	}
	cout << n <<" "<< m;
return 0;
} 
