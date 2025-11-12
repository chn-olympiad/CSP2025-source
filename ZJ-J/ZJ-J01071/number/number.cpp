#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int c[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	s=" "+s;
	for(int i=1;i<=n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			c[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=c[i];j++){
			cout<<i;
		}
	}
	return 0;
}
