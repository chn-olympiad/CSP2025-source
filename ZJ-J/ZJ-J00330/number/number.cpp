#include<bits/stdc++.h>
#include<string>
#include<vector>
using namespace std;
string s,v;
bool emp(int i,int j){
	return i>j;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			v+=s[i];
		}
	}
	sort(v.begin(),v.end(),emp);
	cout<<v;
	return 0;
}