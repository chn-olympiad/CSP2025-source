#include<bits/stdc++.h>
using namespace std;
string s;
priority_queue<int>q;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			int p=s[i]-'0';
			q.push(p);
		}
	}
	while(!q.empty()){
		printf("%d",q.top());
		q.pop();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


