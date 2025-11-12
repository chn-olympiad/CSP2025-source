#include<bits/stdc++.h>
using namespace std;
string s;
int num[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[s[i]-'0']++;
		}
	}
	int flag=0;
	for(int i=1;i<=9;i++){
		if(num[i]!=0){
			flag=1;
		}
	}
	if(flag==0){
		cout<<0;
		return 0;
	}
	for(int i=9;i>=0;i--){
		if(num[i]>0){
			for(int j=1;j<=num[i];j++){
				printf("%d",i);
			}
		}
	}
	return 0;
}