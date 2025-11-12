#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+7;

vector<char>v;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') v.push_back(s[i]);
	}
	sort(v.begin(),v.end(),greater<int>());
	for(int i=0;i<v.size();i++){
		cout<<v[i];
		if(i==0&&v[i]=='0') break;
	}
	
	
	return 0;
}