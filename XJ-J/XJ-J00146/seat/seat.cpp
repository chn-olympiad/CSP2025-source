#include <bits/stdc++.h>
using namespace std;
const int N = 30;
int n , m , score[N * N] , R , rnk;
int main(){
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	cin>>n>>m;
	for(int i = 1;i <= n * m;i++){
		cin>>score[i];
	}
	R = score[1];
	sort(score + 1 , score + n * m + 1);
	reverse(score + 1 , score + n * m + 1);
	for(int i = 1;i <= n * m;i++){
		if(score[i] == R){
			rnk = i;
			break;
		}
	}
	cout<<((rnk - 1) / n + 1)<<' ';
	if(rnk % (n * 2) > 0 && rnk % (n * 2) <= n){
		cout<<rnk % (n * 2);
	}else{
		cout<<n + 1 - (rnk % (n * 2) - n);
	}
}
