#include<bits/stdc++.h>
#define int long long
#define FREOPEN(x) freopen(x ".in","r",stdin),freopen(x ".out","w",stdout);
using namespace std;
priority_queue<int> q;
signed main() {
	FREOPEN("number")
	char c;
	while(cin>>c) {
		if(isdigit(c)) {
			q.push(c-'0');
		}
	} while(!q.empty()) {
		cout<<q.top();
		q.pop();
	}
	return 0;
}
