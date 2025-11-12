#include<bits/stdc++.h>
using namespace std;
string s;
int t[10];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>s;
	for(auto c:s){
		if(!isdigit(c))	continue;
		t[c-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(t[i])	cout<<i,t[i]--;
	}
	return 0;
}
