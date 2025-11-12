#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
vector<ll>vec;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(ll i=0; i<s.size(); i++){
		if(s[i]>='0'&&s[i]<='9')vec.push_back(s[i]-'0');
	}
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	for(auto v:vec)cout<<v;
	return 0;
} 
