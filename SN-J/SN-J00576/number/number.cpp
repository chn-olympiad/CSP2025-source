#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
	string s;
	cin>>s;
	
	int size = 1624;//cout<<size;//判断字符串大小
	char a[size] = {};
	char num[size] = {};
	for(int i = 0;i<size;i++){
		a[i] = s[i];
	}
	for(int i = 0;i<size;i++){
	//	cout<<a[i]<<" ";
	}//将字符串转为列表，ok 
	for(int i = 0;i<size;i++){
		if(a[i]>=48&&a[i]<=57){
			num[i] = a[i];
			//cout<<a[i];数字提取,ok 
		}
	}
	sort(num,num+size);
	for(int i = sizeof(num);i>=0;i--){
		if(num[i]>=48&&num[i]<=57){
			cout<<num[i];
		}
	}
	return 0;
}
