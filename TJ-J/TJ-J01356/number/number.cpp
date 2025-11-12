#include<bits/stdc++.h>
using namespace std;

#define int long long

bool cmp(int x, int y){
	return x>y;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	vector<int> v;
	for(int i = 0; i<s.length();i++){
		if(s[i] == '0'){
			v.push_back(0);
		}else if(s[i] == '1'){
			v.push_back(1);
		}else if(s[i] == '2'){
			v.push_back(2);
		}else if(s[i] == '3'){
			v.push_back(3);
		}else if(s[i] == '4'){
			v.push_back(4);
		}else if(s[i] == '5'){
			v.push_back(5);
		}else if(s[i] == '6'){
			v.push_back(6);
		}else if(s[i] == '7'){
			v.push_back(7);
		}else if(s[i] == '8'){
			v.push_back(8);
		}else if(s[i] == '9'){
			v.push_back(9);
		}
	}
	sort(v.begin(),v.end(),cmp);
	if(v[0] == 0){
		cout<<0;
	}else{
		for(int i = 0; i<v.size();i++){
			cout<<v[i];
		}
	}
	return 0;
}
