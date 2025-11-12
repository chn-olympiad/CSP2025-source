#include<bits\stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a,c=0;
	cin>>s;
	a=int(s.size());
	int b[a]; 
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			b[c]=int(s[i]);
			c++;	}	}
	sort(b,b+c);
	for(int i=c;i>=0;i--){
		cout<<char(b[i]);}
	return 0;}
