#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	vector<char>vec;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
		
	vec.push_back(s[i]);
}	}sort(vec.begin(),vec.end());
for(int i=vec.size()-1;i>=0;i--){
	cout<<vec[i];
}
	return 0;
} 
