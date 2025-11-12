#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[10]={};
	string s;
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	if(a[1]||a[2]||a[3]||a[4]||a[5]||a[6]||a[7]||a[8]||a[9]){
		for(int i=9;i>=0;i--){
			for(int j=0;j<a[i];j++){
				cout<<i;
			}
		}
	}else{
		cout<<0;
	}
	return 0;
}
