#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[110];
string s;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(ll i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') a[s[i]-'0']++;
	}
	for(ll i=9;i>=0;i--){
		while(a[i]--){
			cout<<i;
		}
	}
	cout<<'\n';
	return 0;
}
