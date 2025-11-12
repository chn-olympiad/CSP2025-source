#include <bits/stdc++.h>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
string p(int n){
	string s="";
	while(n>0){
		s+=n%2;
		n/=2;
	}
	reverse(s.begin(),s.end());
	return s;
} 
string p1(string s,string s1){
	string s2="";
	if(s.size()>=s1.size()){
		s2+=s.substr(0,s.size()-s1.size());
		s=s.substr(s.size()-s1.size(),s1.size());
		for(int i=0;i<s1.size();i++){
			if(s[i]==s1[i]) s2+='0';
			else s2+='1';
		}
	}else{
		s2+=s1.substr(0,s1.size()-s.size());
		s1=s1.substr(s1.size()-s.size(),s.size());
		for(int i=0;i<s.size();i++){
			if(s[i]==s1[i]) s2+='0';
			else s2+='1';
		}
	}
	return s2;
}
int p2(string s){
	int n=0;
	int j=0;
	for(int i=s.size();i>=0;i++){
		n+=pow(2,j)*(s[i]-'A'+17);
		j++;
	}
}
int main(int argc, char** argv) {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n+1];
	for(int i=1;i<=n;i++) cin>>a[i];
	string s[n+1];
	for(int i=1;i<=n;i++) s[i]=p(a[i]);
	int c=0;
	for(int i=1;i<=n;i++){
		c+=p2(p1(s[i],s[i+1]));
	}
	return 0;
}
