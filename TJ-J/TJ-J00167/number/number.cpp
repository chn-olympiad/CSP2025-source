#include <bits/stdc++.h> 
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	
	string s;
	int sum[10]={};
	cin>>s;
	for(int i=0;i<10;i++) sum[i]=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			sum[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<sum[i];j++) cout<<i;
	}
	cout<<endl;
	return 0;
}
