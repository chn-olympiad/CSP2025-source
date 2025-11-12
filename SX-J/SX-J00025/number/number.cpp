#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int b=0;
	vector<int> a(s.size());
	for(int i=0;i<s.size();i++){
		if(int(s[i])>=48&&int(s[i])<=57){
			a[b]=int(s[i])-48;
			b++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<b;j++){
			if(a[j]==i){
				cout<<a[j];
			}
		}
	}
	return 0;
}