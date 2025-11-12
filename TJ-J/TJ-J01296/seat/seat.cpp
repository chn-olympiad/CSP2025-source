#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
#include<cstdio>
/*
2 2
98 99 100 97
3 3
94 95 96 97 98 99 100 93 92
4 4
98 94 93 92 13 43 42 89 88 100 23 42 86 54 87 12
2 3
89 78 92 94 69 100
*/
using namespace std;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int hang, lie, temp, a1, shu = 0, a11, flag = 0;
	cin >> hang >> lie;
	shu = hang * lie;
	int a[hang + 1][lie + 1], b[shu + 1];
	for(int i = 0; i <= shu - 1; i++){
		cin >> b[i];
	}
	
	//cout << shu << endl;
	
	a1 = b[0];
	for(int i = 0; i <= shu - 1; i++){
		for(int j = i; j >= 1; j--){
			if(b[j] > b[j - 1]){
				temp = b[j];
				b[j] = b[j - 1];
				b [j - 1] = temp;
			}
		}
	}
	for(int i = 0; i <= shu; i++)
	{
		if(b[i] == a1){
			a11 = i + 1;
			break;
		}
	}
	
//	for(int i = 0; i <= shu - 1; i++){
//		cout << b[i] << " ";
//	}
//	cout << endl << a11 << endl;
	
	for(int i = 0; i <= lie - 1; i++){
		//if(i % 2 != 0){
			for(int j = 0; j <= hang - 1; j++){
				flag++;
				if(flag == a11){
					cout << i + 1 << " " << j + 1 << " " << endl;
					break;
				}
			}
		//}
		//else if(i % 2 == 0){
		i++;
			for(int j = hang - 1; j >= 0; j--){
				flag++;
				if(flag == a11){
					cout << i + 1 << " " << j + 1 << " " << endl;
				}
			}
		//}
		if(flag == a11 || i >= lie) break;
		//flag++;
	}
	return 0;
}
