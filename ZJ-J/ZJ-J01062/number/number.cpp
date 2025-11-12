#include <bits/stdc++.h>
using namespace std;
#define ll long long

int l;
char c;
vector<int> v;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>c) {
		if(c>='0'&&c<='9') {
			v.push_back(c-'0');
		}
	}
	sort(v.begin(),v.end(),greater<int>());
	l=v.size();
	for(int i=0; i<l; i++) {
		cout<<v[i];
	}
	return 0;
}
