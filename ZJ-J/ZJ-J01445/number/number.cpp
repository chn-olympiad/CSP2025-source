#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(char x,char y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	vector <char> v;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' and s[i]<='9'){
			v.push_back(s[i]);
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(char x:v){
		cout<<x;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}