#include <iostream>
#include <queue>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	priority_queue<int> pq;
	string s;
	cin>>s;
	for(size_t i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			pq.push(s[i]-'0');
		}
	}
	if(!pq.empty()){
		if(pq.top()==0){
			cout<<0;
			return 0;
		}
	}
	while(!pq.empty()){
		cout<<pq.top();
		pq.pop();
	}
	
	return 0;
}
