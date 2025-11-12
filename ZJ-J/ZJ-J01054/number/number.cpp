#include<bits/stdc++.h>
using namespace std;
map<long long ,long long> mp;
int main(){
    freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')mp[s[i]-'0']++;
	}
	for(long long i=9;i>=0;i--){
		while(mp[i]--){
			cout<<i;
		}
	}
	return 0;
}
