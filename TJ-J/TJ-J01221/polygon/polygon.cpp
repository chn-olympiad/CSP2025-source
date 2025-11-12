#include<bits/stdc++.h>
using namespace std;
ifstream fin("polygon.in");
ofstream fout("polygon.out");
int main(){
	int n,c,e,f;
	fin>>n;
	int a[n]={};
	fin>>a[n];
	for(int i=1;i<=n;i++){
		c=a[i]+a[i-1];
		if(a[i]>a[0]){
			a[0] = a[i];
			e = a[0];
		}
		if(n>=3 && c>2*e){
			for(int j=1;j<=n;j++){
				f = a[j]+a[j+1];
			}
		}
	}
	fout<<f;
	return 0;
}

