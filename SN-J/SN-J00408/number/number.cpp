#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	string s1="";
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			s1+=s[i];
		}
	}
	for(int j=1;j<s1.size();j++){
		for(int i=1;i<s1.size();i++){
			if(s1[i]>s1[i-1]){
				swap(s1[i],s1[i-1]);
			}
		}
	}
	cout<<s1;
	return 0;
}
