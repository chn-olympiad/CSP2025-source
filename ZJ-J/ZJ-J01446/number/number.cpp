#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define LL long long
#define ULL unsigned long long
#define PII pair<int,int>
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string s;cin>>s;
	int len=s.size();
	priority_queue<char> q;
	for(int i=0;i<len;i++){
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
