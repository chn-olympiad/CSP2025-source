#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	priority_queue<int>q;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			q.push(s[i]-'0');
		}
	}if(q.top()==0){
		cout<<0;
		return 0;
	}
	while(!q.empty()){
		cout<<q.top();
		q.pop();
	}fclose(stdin);
	fclose(stdout);
	return 0;
}