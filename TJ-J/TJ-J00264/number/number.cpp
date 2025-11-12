#include<bits/stdc++.h>
//#define int long long
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	vector<int> v;
	string str;
	cin >> str;
	for(int i=0;i<str.size();i++){
		char x=str[i];
		if('0'<=x&&x<='9'){
			v.push_back(x-'0');
		}
	}
	sort(v.begin(),v.end());
	for(int i=v.size()-1;i>=0;i--){
		cout << v[i];
	}
	return 0;
}

