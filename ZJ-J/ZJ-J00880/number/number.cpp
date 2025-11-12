#include<bits/stdc++.h>
using namespace std;
priority_queue<int> q;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if('0'<=s[i] && s[i] <= '9'){
			q.push(s[i]-48);
		}
	}
	while(!q.empty()){
		cout<<q.top();
		q.pop();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}