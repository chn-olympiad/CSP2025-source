#include<bits/stdc++.h>
using namespace std;
priority_queue<int> q;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			q.push(s[i]-'0');
		}
	}
	while(q.size()){
		int x=q.top();
		q.pop();
		printf("%d",x);
	}
	printf("\n");
	return 0;
}
