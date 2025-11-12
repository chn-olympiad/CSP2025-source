//SN-J00881，纪柯元，西安市曲江第一中学// 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char number[1000]={};
	int a[1000]={};

	string s;
	int k=1;
	cin>>s;
	for(int i=1;i<=s.length();i++){
		number[i]=s[i-1];
	}
	for(int i=1;i<=s.length();i++){
		if((number[i]-'0'>=0)&&(number[i]-'0'<=9)){
			int m=number[i]-'0';
			a[k]=m;
			k++;
		}
		}
	
	
	sort(a+1,a+k+1);
	for(int i=k;i>=2;i--){
		cout<<a[i];
		
		
		
		
	}
	
return 0;

	
	
	
}
