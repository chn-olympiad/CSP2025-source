#include<bits/stdc++.h>
using namespace std;
ifstream fin("xor.in");
ofstream fout("xor.out");
int main(){
	int n,k;
	int a[n]={};
	fin>>n>>k;
	fin>>a[n];
	for(int i=1;i<=n;i++){
		if(k = a[i]+a[i-1]){
			fout<<i;
		}
		else{
			a[i]=a[1];
		}
	}
	return 0;
}
