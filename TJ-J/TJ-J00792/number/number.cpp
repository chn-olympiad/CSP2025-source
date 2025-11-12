#include<bits/stdc++.h>
using namespace std;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,ss;
	cin>>s;
	for(char c:s){
		if(c>='0'&&c<='9'){
			ss+=c;
		}
	}
	sort(ss.begin(),ss.end(),cmp);
	cout<<ss<<endl;



	return 0;
}

