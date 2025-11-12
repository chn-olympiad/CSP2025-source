#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,ans;
ll a[50];
bool flag=0;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	n=s.size();
	for(ll i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9') a[s[i]-'0']++;
	}
	for(ll i=9;i>=1;i--){
		if(a[i]!=0) flag=1;
	}
	if(flag){
		for(ll i=9;i>=0;i--){
			for(ll j=1;j<=a[i];j++){
				cout<<i;
			}
		}
		cout<<"\n";
	}else cout<<"0\n";
	return 0;
}
