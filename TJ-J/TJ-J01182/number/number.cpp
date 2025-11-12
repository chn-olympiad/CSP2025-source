#include<iostream>
using namespace std;
int main(){ 
	freopen("std","r",number.in);
	freopen("std","w",number.out);
	int t[11]={0};
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			int a=s[i]-'0';
			t[a]++;
		}
	}
	for(int i=9;i>=0;i++){
		for(int j=0;j<t[i];j++){
			cout<<i;
		}
	}
} 
