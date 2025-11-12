#include<bits/stdc++.h>
using namespace std;
string str,s;
int a[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	bool f=0;
	for(int i=0;i<str.size();i++){
		if(str[i]>='0'&&str[i]<='9'){
			a[str[i]-'0']++;
			if(str[i]!='0')	f=1;
		}	
	}
	if(f){
		for(int i=9;i>=0;i--){
			for(int j=a[i];j>0;j--){
				cout<<i;
			}
		}
	}
	else{
		cout<<0;
	}
	return 0;
}
