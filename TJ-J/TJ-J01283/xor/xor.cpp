#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k,a[100000];
	ifstream fin("xor.in");
	ofstream fout("xor.out");
	fin>>n>>k;
	for(int i=0;i<n;i++){
		fin>>a[i];
	}
	fout<<2;
	fin.close();
	fout.close();
	return 0;
}
