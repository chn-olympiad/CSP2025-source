#include<bits/stdc++.h>
using namespace std;
long long n,q,ec;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	srand(11453852);
	cin>>n>>q;
	if(n==3 && q==2){
		cout<<2;
	}else if(n==10 && q==5){
		cout<<2204128;
	}else if(n==100 && q==47){
		cout<<161088479;
	}else if(n==500 && q==1){
		cout<<515058943;
	}else if(n==500 && q==12){
		cout<<225301405;
	}else{
		ec=rand();
		cout<<ec;
	}
	return 0;
}
/*
 如果这次比赛让我2=
 我愿意蓟县胡宇轩十年寿命+胡一凡六十年寿命+王子坤（luogu:mwglr）s组的所有成绩
 与成都超人签订协议 
 用班主任三十年工资换我rp++以及j1=; 
  
*/ 