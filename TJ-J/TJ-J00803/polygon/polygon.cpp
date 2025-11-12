#include<bits/stdc++.h>
using namespace std;
int a[114514];
int main(){
	freopen("polygon.in","r","stdin");
	freout("polygon.out","w","stdout");
	int n;
	cin >> n;
	for (int i=1; i<= n; i++){
		cin >> a[i];
	}
	cout << a[n];
return 0;
}
