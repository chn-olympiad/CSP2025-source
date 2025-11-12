#include<bits/stdc++.h>
using namespace std;
string s,k;

bool cmp(char x,char y){
	return x>y;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	cin>>s;
	sort(s.begin(),s.end(),cmp);
	for(int i=0;i<s.size();i++)
		if(isdigit(s[i]))
			k.push_back(s[i]);
	cout<<k;
	return 0;
}
