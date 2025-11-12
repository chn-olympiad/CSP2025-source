#include<bits/stdc++.h>
using namespace std;
int t[110];
int n,m;
int ft;
int fti;
int k;
int main(){
	cin >> n >> m;
	cin >> ft;
	for(int i = 1;i < n*m;i++){
		int h = 0;
		cin >> h;
		t[h]++;
	}
	for(int i = 0;i < 100;i++){
		//cout << 9 << endl;
		if(t[i] != 0){
			k++;
			//cout << i << endl;
			if(i > ft){
				fti = k-1;
			}
		}
	}
	//cout << fti;
	/*
3 3
94 95 96 97 98 99 100 93 92
	*/
	cout << (fti-(fti%n))/n+1 << " ";
	if(((fti-(fti%n))/n+1)%2 == 0){
		cout << n-(fti%n);
	}else{
		cout << (fti%n)+1;
	}
}
