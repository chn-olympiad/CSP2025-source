#include<bits/stdc++.h>
using namespace std;
string s;
priority_queue<char> q;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++)if(isdigit(s[i]))q.push(s[i]);
	while(q.size()){
		cout<<q.top();
		q.pop();
	}
	fclose(stdin);fclose(stdout);
}
