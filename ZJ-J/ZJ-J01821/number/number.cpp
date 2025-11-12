#include<bits/stdc++.h>
using namespace std;
long long a[10];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	bool f=false;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
			if(s[i]!='0')f=true;
		}
	}
	if(f==false)cout<<0;
	else{
		for(int i=9;i>=0;i--){
			for(int j=1;j<=a[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
}