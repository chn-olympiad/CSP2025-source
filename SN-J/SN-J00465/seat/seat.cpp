//SN-J00465 方立轩 安康长兴综合高级中学 
#include <iostream>
#include <fstream>
using namespace std;
int main(){
	ifstream fin("seat.in");
	ofstream fout("seat.out");
	int n, m, cnt = 1, a, b;
	fin >> n >> m;
	int c[n];
	for(int i = 1; i <= n * m; i++){
		cin >> c[i];
	}
	for(int i = 2; i <= n * m; i++){
		if(c[i] > c[1]){
			cnt += 1;
		}
	}
	a = cnt / n + 1;
	b = cnt % n;
	if(a % 2 == 0){
		b = n - b;
	}
	fout << a << " " << b;
	return 0;
}
