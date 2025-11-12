#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	froprin(cin,number.in,"r");
	froprin(cout,number.out,"w");
	string s,s1;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]-'A'<9) s1+=s[i];
	}
	sort(s1.begin(),s1.end()+1);
	for(int i=s1.size();i>0;i--) cout<<s1[i];
	return 0;
}
