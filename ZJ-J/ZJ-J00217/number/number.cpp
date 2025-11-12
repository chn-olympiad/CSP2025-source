#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	priority_queue<int>pq;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			pq.push(s[i]-'0');
		}
	}
	while(!pq.empty()){
		int g=pq.top();
		cout<<g;
		pq.pop();
	}
	return 0;
}
