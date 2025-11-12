#include<bits/stdc++.h>
using namespace std;
priority_queue<int>Q;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			Q.push(s[i]-'0');
		}
	}
	while(!Q.empty()){
		cout<<Q.top();
		Q.pop();
	}
	return 0;
}
