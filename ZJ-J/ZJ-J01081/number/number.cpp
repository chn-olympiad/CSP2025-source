#include<bits/stdc++.h>
using namespace std;
int c[1001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			int x=s[i]-'0';
			c[x]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=c[i];j++){
			cout<<i;
		}
	}
	return 0;
}
