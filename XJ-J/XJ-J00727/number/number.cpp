#include<bits/stdc++.h>
using namespace std;
string s;
int a[10001],n/*数字数量*/=0;
int main(){
	//录入字符串S
	getline(cin,s);
	
	//提取数字
	for(int i=0;i<s.size();i++){
	if((s[i]-'0')>=0&&(s[i]-'0')<=9){
		a[n]=s[i]-'0';
		n++;
	}
	}
	
	//排序输出
	sort(a,a+n);
	for(int i=n-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
