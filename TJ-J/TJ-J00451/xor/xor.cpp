#include<iostream>
#include<fstream>
using namespace std;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	long long n, k;
	cin >> n >> k;
	bool** a = new bool*[n];
	bool* b = new bool*[n];
	for(long long i = 0;i < n;i++){
		a[i] = new bool[21];
		for(long long j = 0;j < 21;j++){
			a[i][j] = 0;
		}
	}
	for(long long i = 0;i < n;i++){
		cin >> b;
		
	}
	cout << 0;
	return 0;
}
