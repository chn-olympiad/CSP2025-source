#include<bits/stdc++.h>
int a[1000000];
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
 	string s;cin>>s;
 	if(s.size()==1){
		cout<<s;
		return 0;
	}
	if(s.size()==2){
		cout<<s;
		return 0;
	}
	for(int i=1;i<=s.size;i++){
		if(s[i]>='0'&&s[i]<='9'){
			cout<<s[i];
		}
	}
	return 0;
}