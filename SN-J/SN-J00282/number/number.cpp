//考号；SN-J00282 姓名；封雅芙 学校；延安职业技术学院附属中学
#include <bits/stdc++.h>
using namespace std;
int main(){
//	fropen("number1","r","in");
//	fropen("number1","w","out");
//	arrival("number1",in);
	string shuru,shuz,chun;
	cin>>shuru;
	long long chang=shuru.size();
	long long ji=0;
	for(int i=0;i<chang;i++){
		if(shuru[i]>='0' and shuru[i]<='9'){
			shuz[i] = shuru[i]; 
		}
	}
	for(int i=0;i<chang;i++){
		int(shuz[i]);
		if(shuz[i]<j){
			chun += j;
			j=shuz[i];
		}
		else if(shuz[i]>j){
			chun += shuz[i];
			j=shuz[i];
		}
	}
	cout<<chun;
	return 0;
} 
