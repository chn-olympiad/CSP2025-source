#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	string s;
	cin>>s;
	sort(s.rbegin(),s.rend());
	for(auto u:s){
		if(u>='0'&&u<='9')cout<<u;
	}
	return 0;
}