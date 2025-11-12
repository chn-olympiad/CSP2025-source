#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,s1,s2;
	cin>>s;
	for(int i=0;i<s.size();i++){
		int x=(char)(s[i])-'0';
		if(x==0||x==1||x==2||x==3||x==4||x==5||x==6||x==7||x==8||x==9){
			s1+=s[i];
		}
	}
	for(int j=0;j<s1.size();j++){
		int maxx=-1,max_index=0;
		for(int i=0;i<s1.size();i++){
			if(s1[i]-48>maxx){
				maxx=s1[i]-48;
				max_index=i;
			}
		}
		s2+=s1[max_index];
		s1[max_index]=' ';
	}
	for(int i=0;i<s2.size();i++){
		cout<<s2[i]-48;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
