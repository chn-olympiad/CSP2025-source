#include<bits/stdc++.h>
using namespace std;
int a[10],f;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=1;i<=9;i++){
		if(a[i]) f=1;
	}
	if(f){
		for(int i=9;i>=0;i--){
			while(a[i]>0){
				cout<<i;
				a[i]--;
			}
		}	
	}
	else{
		cout<<0;
	}
	return 0;
} 
