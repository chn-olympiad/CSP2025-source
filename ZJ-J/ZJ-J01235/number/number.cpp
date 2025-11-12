#include<bits/stdc++.h>
using namespace std;
string s;
priority_queue<int ,vector<int> , greater<int> > q;
stack<int> p;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
			q.push(s[i]-'0');
	while(!q.empty()){
		p.push(q.top());
		q.pop();
	}
	while(!p.empty()){
		cout<<p.top();
		p.pop();
	}
	return 0;
} 
