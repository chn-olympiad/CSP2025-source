#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	int m=0;
	freopen("number.in","r",stdin);
	freopen("number.out","d",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			m++;
		}
		for(int j=1;j<=m;j++){
			if(s[i]<s[i+1]){
				int v=s[i+1];
				s[i+1]=s[i];
				s[i]=v;
			}
		}
		if(s[i]>='0'&&s[i]<='9'){
			cout<<s[i];
		}
	}
	return 0;
} 
