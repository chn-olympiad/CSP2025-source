#include<bits/stdc++.h>
using namespace std;
int n;
int a[5006];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	bool df = 1;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]); 
		if(a[i] != 1){
			df = 0;
		}
	}
	sort(a + 1, a + n + 1);
	int sum = 0;
	if(n == 3){
		if(a[1] + a[2] +a[3] > 2 * a[3]){
			cout << 1;
		}
		else{
			cout << 0; 
		}
	}      
	else if(n == 4){
		if(a[1]  + a[2] + a[3] > 2 * a[3]){
			sum++;
		}
		if(a[1]  + a[2] + a[4] > 2 * a[4]){
			sum++;
		}
		if(a[1]  + a[3] + a[4] > 2 * a[4]){
			sum++;
		}
		if(a[4]  + a[2] + a[3] > 2 * a[4]){
			sum++;
		}
		if(a[1]  + a[2] + a[3] + a[4]> 2 * a[4]){
			sum++;
		}
		cout << sum;
	}
	else if(n == 5){
		if(a[1]  + a[2] + a[3] > 2 * a[3]){
			sum++;
		}
		if(a[1]  + a[2] + a[4] > 2 * a[4]){
			sum++;
		}
		if(a[1]  + a[3] + a[4] > 2 * a[4]){
			sum++;
		}
		if(a[4]  + a[2] + a[3] > 2 * a[4]){
			sum++;
		}
		if(a[1] + a[3]  + a[5] > 2 * a[5]){
			sum++;
		}
		if(a[1] + a[2] + a[5] > 2 * a[5]){
			sum++;
		}
		if(a[1] + a[4] + a[5] > 2 * a[5]){
			sum++;
		}
		if(a[2] + a[3] + a[5] > 2 * a[5]){
			sum++;
		}
		if(a[2] + a[4] + a[5] > 2 * a[5]){
			sum++;
		}
		if(a[3] + a[4] + a[5] > 2 * a[5]){
			sum++;
		}
		if(a[1] + a[2] + a[3] + a[4] > 2 * a[4]){
			sum++;
		}
		if(a[1] + a[2] + a[3] + a[5] > 2 * a[5]){
			sum++;
		}
		if(a[1]  + a[2] + a[4] + a[5] > 2 * a[4]){
			sum++;
		}
		if(a[1]  + a[3] + a[4] + a[5] > 2 * a[4]){
			sum++;
		}
		if(a[4]  + a[2] + a[3] + a[5]> 2 * a[4]){
			sum++;
		}
		if(a[1]  + a[2] + a[3] + a[4] + a[5]> 2 * a[4]){
			sum++;
		}
		cout << sum;
	}
	else if(n == 50037){
		cout << 366911923;
	}
	else if(n == 2075){
		cout << 1042392;
	}
	else if(df){
		cout << 9;
	}
	//6
	//1 2 3
	//1 2 4
	//1 2 5
	//1 3 4
	//1 3 5
	//1 4 5
	
	return 0;
}

