#include<bits/stdc++.h>
using namespace std;
priority_queue<int > heap;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	char t;
	while(cin>>t){
		if('0'<=t && t<='9'){
			heap.push(t-'0');
		}
	}
	while(!heap.empty()){
		cout<<heap.top();
		heap.pop();
	}
	return 0;
}

