#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long n=s.size();
	priority_queue<char> q;
	for(long long i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			q.push(s[i]);
		}
	}
	while(!q.empty()){
		cout<<q.top();
		q.pop();
	}
	return 0;
}
