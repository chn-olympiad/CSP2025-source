#include<bits/stdc++.h>
using namespace std;
int n = 0;
int m = 0;
int a[15][15];
int score[1000];
int myscore = 0;
int whe = 0;
int k = 0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	k = n*m;
	for(int i = 0;i<k;i++){
		cin >> score[i];
	}
	myscore = score[0];
	sort(score,score+k);
	for(int i = 0;i<k;i++){
		if(score[i] == myscore){
			whe = k-i;
		}
	}
	int x = 0;
	int y = 0;
	if(whe%n==0){
		x = whe/n;
		if((whe/n)%2==0){
			y = 1;
		}
		else{
			y = m;
		}
		cout<<x<<' '<<y;
	}
	else if(whe%n!=0){
		x = whe/n+1;
		if((whe/n+1)%2==0){
			y = m-whe%n+1;
		}
		else{
			y = whe%n;
		}
		cout<<x<<' '<<y;
	}
	return 0;
}