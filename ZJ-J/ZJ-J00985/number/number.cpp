#include <bits/stdc++.h>

using namespace std;
string s;
priority_queue <int> ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(auto it:s){
		if(it>='0'&&it<='9'){
			ans.push((int)(it-'0'));
		}
	}
	long long cnt=0;
	while(!ans.empty()){
		cnt=cnt*10+ans.top();
		ans.pop();
	}
	cout<<cnt<<endl;
	return 0;
}

