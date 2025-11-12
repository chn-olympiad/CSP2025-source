#include<bits/stdc++.h>
using namespace std;
//freopen?
//long long?
//memset?
/*
100 pts
*/
string s;
priority_queue<int>p;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0' && s[i]<='9'){
			p.push(int(s[i]-'0'));
		}
	}
	while(!p.empty()){
		cout<<p.top();
		p.pop();
	}
	return 0;
}