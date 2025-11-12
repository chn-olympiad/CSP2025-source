#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	cin >> str;
	vector<int>v;
	for(int i=0;i<str.size();i++){
		if(str[i]<='9' && str[i]>='0'){
			v.push_back(str[i]-'0');
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++){
		cout << v[i];
	}
	return 0;
}
