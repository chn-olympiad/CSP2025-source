#include <bits/stdc++.h>
using namespace std;

int todi(char c){
	return c - '0';
}

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	priority_queue<int> max_heap;
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(isdigit(s[i])){
			max_heap.push(todi(s[i]));
		}
	}
	while(!max_heap.empty()){
		cout << max_heap.top();
		max_heap.pop();
	}
	
	
	return 0;
} 
