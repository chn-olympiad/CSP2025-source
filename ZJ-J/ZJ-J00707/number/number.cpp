#include<bits/stdc++.h>
using namespace std;
int t[10];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	char s;
	while(cin>>s){
		if(s>='0'&&s<='9'){
			t[s-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(t[i]){
			cout<<i;
			t[i]--;
		}
	}
	return 0;
}
