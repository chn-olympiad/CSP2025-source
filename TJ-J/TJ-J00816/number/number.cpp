#include <bits/stdc++.h>
using namespace std;
priority_queue <int> q;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int cnt=0; 
	cin>>s;
	for(int i=0;i<s.size();++i){
		if(s[i]<='9'&&s[i]>='0'){
			q.push(s[i]-'0');
			cnt++;
		}

	}
	for(int i=0;i<cnt;i++){
		cout<<q.top();
		q.pop();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
