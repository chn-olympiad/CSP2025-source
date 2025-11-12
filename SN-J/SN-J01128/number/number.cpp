//陶家轩 SN-J01128 西安市曲江第一学校 
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	string s;
	cin>>s;
	if(s.size()==1){
		cout<<s;
		return 0;
	}
	vector<int> a;
	for(int i=0;i<=s.size();i++){
		if(s[i]>=48&&s[i]<=57){
			a.push_back(s[i]-48);
		}
	}
	sort(a.begin(),a.end(),cmp);
	for(int i=0;i<a.size();i++){
		cout<<a[i];
	}
	return 0;
}
