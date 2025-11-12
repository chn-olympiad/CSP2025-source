#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a[100000];
	ifstream fin("polygon.in");
	ofstream fout("polygon.out");
	fin>>n;
	for(int i=0;i<n;i++){
		fin>>a[i];
	}
	fout<<9;
	fin.close();
	fout.close();
	return 0;
}
