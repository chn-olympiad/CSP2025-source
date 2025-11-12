#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<cmath>
using namespace std;
string num;
long long a[1000005],j;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>num;
	for(int i=0;i<num.size();i++){
		if(num[i]>='0'&&num[i]<='9'){
			a[j]=(num[i]-'0');
			j++;
		}
	}
	sort(a+0,a+j+1);
	if(a[j]==0){
		cout<<0;
	}else{
		for(int i=j;i>0;i--){
			cout<<a[i];
		}
	}
	return 0;
}
