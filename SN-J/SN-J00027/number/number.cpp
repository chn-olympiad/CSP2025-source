#include<bits/stdc++.h>
using namespace std;
string s;
priority_queue<int> q;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			q.push(s[i]-'0');
		}
	}
	if(q.top()==0){
		cout<<0;
		return 0;
	}
	while(q.empty()==0){
		cout<<q.top();
		q.pop();
	}
	return 0;
}
