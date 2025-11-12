#include<bits/stdc++.h>
using namespace std;
/*
int xor(int n,int m){
	vector<int> nt;
	whil(n > 0){
		nt.push_back(n%2);
		n = (n-(n%2))/2;
	}
	vector<int> mt;
	whil(m > 0){
		mt.push_back(m%2);
		m = (m-(m%2))/2;
	}
	/*
	for(int i = 0;i < max(nt.size(),mt.size());i++){
		
	}
	*/

int main(){
	int n,k;
	cin >> n >> k;
	int list[n];
	for(int i = 0;i < n;i++){
		cin >> list[i];
	}
	if(n == 1){
		cout << 2;
	}
	return 0;
}
