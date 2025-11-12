#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
string s;
priority_queue<int> q;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			int k=s[i]-'0';
			q.push(k);
		}
	}
	while(q.size()){
		int t=q.top();
		q.pop();
		cout<<t;
	}
	return 0;
}

