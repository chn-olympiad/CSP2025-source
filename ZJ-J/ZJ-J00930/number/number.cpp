#include<bits/stdc++.h>
using namespace std;
int ans;
string s;
vector<int> vec;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	vec.clear();
	int len=s.size();
	for(int i=0;i<len;++i){
		if(s[i]>='0'&&s[i]<='9'){
			vec.push_back((s[i]-'0'));
		}
	}

	sort(vec.begin(),vec.end(),greater<int>());
	for(int i=0;i<vec.size();i++){
		cout << vec[i];
	}
	return 0;
}
