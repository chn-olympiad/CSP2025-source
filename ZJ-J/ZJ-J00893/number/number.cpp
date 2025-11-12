#include <bits/stdc++.h>
using namespace std;

const int N = +10;

string s,res;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(char c:s){
		if(c>='0'&&c<='9'){
			res.push_back(c);
		}
	}
	sort(res.begin(),res.end(),greater<char>());
	cout<<res<<endl;
	return 0;
}