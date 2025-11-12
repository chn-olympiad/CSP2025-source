#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
string s;
ll vis[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>s;
	for(ll i=0;i<=s.size()-1;i++){
		if(s[i]>='0'&&s[i]<='9'){
			vis[s[i]-'0']++;
		}
	}
	for(ll i=9;i>=0;i--){
		for(ll j=1;j<=vis[i];j++){
			cout<<i;
		}
	}
	return 0;
}
