#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,m,a[100005];
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(a[1] | a[2]){
		cout << 1 << endl; 
	} 
	return 0;
}
