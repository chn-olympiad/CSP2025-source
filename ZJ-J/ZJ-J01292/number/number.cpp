#include<bits/stdc++.h>
using namespace std;
string a;
priority_queue<int>q;
int main(void){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int l=a.size();
	for(int i=0;i<l;i++){
		if(a[i]>='0'&&a[i]<='9'){
			q.push(a[i]-'0');
		}
	}
	while(!q.empty()){
		cout<<q.top();
		q.pop();
	}
	return 0;
}
