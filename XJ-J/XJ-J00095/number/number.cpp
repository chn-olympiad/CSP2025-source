#include <bits/stdc++.h>
using namespace std;
bool cmp(char x,char y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin>>s;
	vector<char> a;
	a.resize(s.size()+1);
	for(auto i:s){
		if(i>='0' && i<='9'){
			a.push_back(i);
		}
	}
	sort(a.begin(),a.end(),cmp);
	for(auto i:a){
		cout<<i;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
