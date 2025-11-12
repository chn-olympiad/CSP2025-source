#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	char c[1000005]={};
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){ 
			c[i]=s[i];
		}
	}
	sort(c,c+s.size());
	for(int i=s.size()-1;i>=0;i--){
		if(c[i]>='0'&&c[i]<='9'){ 
			cout<<c[i];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
