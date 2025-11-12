#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int tong[20];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			tong[s[i]-48]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(tong[i]--){
			cout<<i;
		}
	}
	return 0;
}
