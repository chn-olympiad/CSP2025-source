#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
string s;
priority_queue<int>pq;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s;
	int len = s.length();
	for(int i = 0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9')pq.push(s[i]-48);
	}
	while(!pq.empty()){
		cout<<pq.top();pq.pop();
	}
	return 0;
}
