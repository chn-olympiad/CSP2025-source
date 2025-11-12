#include<bits/stdc++.h>
using namespace std;
int score[1000];


int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int seat = 0 , rn = 0 , rm = 0;
	int n , m;
	cin >> n >> m;
	for(int i = 1;i <= n * m;i ++){
		cin >> score[i];
	}
	for(int i = 2;i <= n * m;i ++){
		if(score[i] > score[1]){
			seat ++;
		}
	}
	seat ++;
	if(seat % n != 0){
		rm = (seat / n) + 1;
	}
	else{
		rm = seat / n;
	}
	if(rm % 2 == 0){
		rn = n - (seat - (rm - 1) * n) + 1;
	}
	else{
		rn = seat - (rm - 1) * n;
	}
	cout << rm << " " << rn << "\n";
	/*
	2 2
    99 100 97 98
    
    2 2
	98 99 100 97
    
    4 5
    11 1 2 3 4 5 6 7 8 9 10 12 13 14 15 16 17 18 19 20 
    
    
    3 3
	94 95 96 97 98 99 100 93 92
	*/
	return 0;
}
