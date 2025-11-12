#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[i];
int main(){
	cin >> n >> m;
	for(int i=0; i<=m*n; i++){
		if(a[i]==i){
			a[i]++;
			cout << a[i];
		}else if(a[i]>=i){
			a[i] = n*m-i+1;
			cout << a[i];
		}
	}
	return 0;
}
