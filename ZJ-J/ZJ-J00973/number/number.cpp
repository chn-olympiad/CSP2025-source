#include<iostream>
#include<string>
using namespace std;
int a[12]={};
int main(){
	//bool flag=false;
	int t;
	string str={};
	cin >> str;
	for(int i = 0;i<=str.size();i++){
		if(str[i]>='0' && str[i] <= '9'){
			t = str[i] - '0';
			a[t]++;
		}
	}
	for(int i = 9;i>=0;i--){
		for(int j = 1;j<=a[i];j++){
			//if(i!=0)flag = true;
			cout << i;
		}
	}
	return 0;
}