#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	
	int n , m;
	cin >> n >> m;
	
	int sum , num = 1;
	cin >> sum;
	
	for(int i = 2;i <= n*m;i++){
		int a;
		cin >> a;
		if(a > sum){
			num++;
		}
	}
	
	int x = 1 , y = 1;
	int number = 1;
	while(true){
		if(num == 1){
			cout<<y<<" "<<x;
			break;
		}
		
		num--;
		if((x == 1 && number == -1) || (x == n && number == 1)){
			number = -number;
			y++;
		}else{
			x = x + number;
		}
	}
	
	return 0;
}
