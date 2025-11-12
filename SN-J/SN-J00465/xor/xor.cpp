//SN-J00465 方立轩 安康长兴综合高级中学 
#include <iostream>
#include <fstream>
using namespace std;
int main(){
	ifstream fin("xor.in");
	ofstream fout("xor.out");
	int n, m, z = 0;
	fin >> n >> m;
	int a[n];
	for(int i = 1; i <= n; i++){
		fin >> a[i];
	}
	for(int i = 1; i <= n; i++){	
		int x = 0, y = 0, cnt = 0;
		for(int j = 1; j <= i; j++){
			x += a[i]; 
			y -= a[i];
			if(x == m){
				cnt++;
				x = 0;
			}
			else if(x + y == m){
				cnt++;
				x = 0;
				y = 0;
			}
			if(cnt >= z){
				z = cnt;
			}
		}
	}
	fout << z;
	return 0;
}
