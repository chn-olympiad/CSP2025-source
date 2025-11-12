#include<bits/stdc++.h>
using namespace std;
string j,s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	vector<char> v;
	int len = s.size();
	for(int i=0;i<len;i++){
		if(isdigit(s[i])){
		    v.push_back(s[i]);
		}
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	for(int i = 0;i<(int)v.size();i++){
		j+=v[i];
	}
	for(int i = 0;i<(int)j.size();i++){
		cout<<j[i]-'0';
	}
	return 0;
}
