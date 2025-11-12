#include<bits/stdc++.h>
using namespace std;
int n[1000010];
int main(){
	freopen("numder","r",stdin);
	freopen("number","w",stdout);
	string s,l="";
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			l+=s[i];
		}
	}
	for(int i=0;i<l.size();i++){
		n[i]=l[i]-'0';
	}
	sort(n,n+l.size());
	for(int i=l.size()-1;i>=0;i--){
		cout<<n[i];
	}
	return 0;
}
