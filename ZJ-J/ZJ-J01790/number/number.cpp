#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	priority_queue<int> que;
	for(int i=0;i<n;i++){
		if(s[i]<'0'||s[i]>'9')continue;
		que.push(s[i]-'0');
	}
	if(que.top()==0){
		cout<<0;
		return 0;
	}
	while(!que.empty()){
		cout<<que.top();
		que.pop();
	}
	return 0;
}
