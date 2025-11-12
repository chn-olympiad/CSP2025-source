//SN-J00389  张爱熙  西安高新第一中学
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
priority_queue<int,vector<int>,less<int> > q;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9') q.push(s[i]-'0');
	}
	while(!q.empty()){
		cout<<q.top();
		q.pop();
	}
	return 0;
}
