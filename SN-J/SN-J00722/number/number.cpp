//SN-J00722 王培翔 雁塔第一学校 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll q,a[15];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(ll i=0;i<s.size();i++){
		a[s[i]-'0']++;
	}
	for(ll i=9;i>=0;i--){
		for(ll j=1;j<=a[i];j++)cout<<i;
	}
	return 0;
}
