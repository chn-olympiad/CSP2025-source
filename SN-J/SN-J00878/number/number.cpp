#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int A[500000];
	for(int i=0;i<=s.size()+1;i++){
		A[i]=-1;
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='0') A[i]=s[i]-'0';
		if(s[i]=='1') A[i]=s[i]-'0';
		if(s[i]=='2') A[i]=s[i]-'0';
		if(s[i]=='3') A[i]=s[i]-'0';
		if(s[i]=='4') A[i]=s[i]-'0';
		if(s[i]=='5') A[i]=s[i]-'0';
		if(s[i]=='6') A[i]=s[i]-'0';
		if(s[i]=='7') A[i]=s[i]-'0';
		if(s[i]=='8') A[i]=s[i]-'0';
		if(s[i]=='9') A[i]=s[i]-'0';
	}
	sort(A,A+s.size());
	for(int i=s.size()-1;i>=0;i--){
		if(A[i]!=-1){
			cout<<A[i];
		}
	}
	return 0;
}
