#include<iostream>
#include<string>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int xyz=-1;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			xyz++;
			a[xyz]=(s[i]-'0');
		}
	}
	int len=xyz+1;
	sort(a,a+len,cmp);
	for(int i=0;i<len;i++){
		cout<<a[i];
	}
	return 0;
} 
