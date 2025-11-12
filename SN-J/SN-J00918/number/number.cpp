#include<bits/stdc++.h>
using namespace std;
string s;
int n,a;
priority_queue<int>pq;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;++i){
		if(isdigit(s[i])){
			a=s[i]-'0';
			pq.push(a);
		}
	}while(!pq.empty()){
		cout<<pq.top();
		pq.pop();
	}return 0;
}
