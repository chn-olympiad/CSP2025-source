#include<bits/stdc++.h>
using namespace std;
int number[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a=s[i]-'0';
			number[a]++;
		}
	}
	int flag=0;
	for(int i=9;i>=0;i--){
		if(i==0&&!flag)cout<<0;
		else if(number[i]>0){
			flag=1;
			while(number[i]){
				number[i]--;
				cout<<i;
			}
		}
	}
	return 0;
}
