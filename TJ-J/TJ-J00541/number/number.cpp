#include<bits/stdc++.h>
using namespace std;
string s;
map <char,int> t;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		t[s[i]]++;
	}
	bool f=0;
	for(int i=9;i>=1;i--){
		if(t[(i+'0')]>=1){
			for(int j=1;j<=t[(i+'0')];j++) cout<<i;
			f=1;
		}
	}
	if(f){
		for(int i=1;i<=t['0'];i++) cout<<0;
	}else{
		cout<<0;
	}
	return 0;
}
