#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
#include<cstdio>
using namespace std;
/*
5
1 2 3 4 5
*/
int n, temp;
int main()
{
	freopen("golygon.in", "r", stdin);
	freopen("golygon.out", "w", stdout);
	cin >> n;
	int a[n + 1];
	for(int i = 0; i <= n - 1; i++){
		cin >> a[i];
	}
	for(int i = 0; i <= n - 1; i++){
		for(int j = i; j >= 1; j--){
			if(a[j] < a[j - 1]){
				temp = a[j];
				a[j] = a[j - 1];
				a [j - 1] = temp;
			}
		}
	}
	
//	for(int i = 0 ; i <= n - 1; i++){
//		cout << a[i] << " "; 
//	}
	
	for(int i = 0; i <= n - 1; i++){
		for(int j = i; j <= n - 1; j++){
			for(int k = j; k <= n - 1; k++){
				
			}
			//cout << endl;
		}
		//cout << endl;
	}
	return 0;
}
