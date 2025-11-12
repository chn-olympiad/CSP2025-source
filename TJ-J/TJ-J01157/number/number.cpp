#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin); 
	freopen("number.out","w",stdout); 
	string s,t,u,f,m;
	int n;
	getline(cin,s);
	if(s.size()==1)cout<<s;
	for(int i=0;i<=s.size()-1;i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			t=t+s[i];
		}
	}
	for(int i=0;i<=t.size()-1;i++){
		for(int j=0;j<t.size()-1;j++){
			if(t[j]>=t[j+1]){
			m=t[j];
			if(m>=u){
			 u=t[j];
			 n=j;}
		 }else{
			 m=t[j+1];
			 if(m>=u){
			 u=t[j+1];
			 n=j+1;}
			}
		}
		t[n]='0';
		f+=u;
		u='0';
	}
	for(int i=0;i<=s.size()-1;i++){
		cout<<f[i];
		}
	
	return 0;
}
