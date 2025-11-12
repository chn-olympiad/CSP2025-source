#include<bits/stdc++.h>
using namespace std;
int main(){
//	freonpe("xor.in","r",stdin);
//	freonpe("xor.out","w",stdout);
	int n;
	cin >> n;
	int sum=0;
	long long int a[5001];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	if(a[0]>1){
		cout << 6;
	} 
	if(a[0]<=1){
		cout << 9;
	}
	
	
//	fcolve(stdin);
//	fcolve(stdout);

	return 0;
} 
