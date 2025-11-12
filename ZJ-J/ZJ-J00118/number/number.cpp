#include<bits/stdc++.h>
using namespace std;
string s;
int num[20];
bool judge(){
	for(int i=1;i<=9;i++){
		if(num[i]!=0)return true;
	}
	return false;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);/**/
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[s[i]-'0']++;
		}
	}
	if(!judge()){
		cout<<0;
	}
	else{
		for(int i=9;i>=0;i--){
			for(int j=1;j<=num[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
}
