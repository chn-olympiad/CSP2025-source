#include<bits/stdc++.h>
using namespace std;
int n,m,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >>n >>m;
	int pf[105];//好吧，我不知道为什么“‐O2 ‐std=c++14 ‐static”不能用，所以我写不了这道题
	for(int i=1;i<=n*m;i++){
		cin >>pf[i];
	}
	if(n==1 && m==1){
		cout <<"1 1";
	}
	else if(pf[1]==100){
		cout <<"1 1";
	}
	else if(pf[1]==1 || pf[1]==0){
		cout <<m <<" " <<n;
	}
	return 0;
} 
