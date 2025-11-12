#include<bits/stdc++.h>
using namespace std;
string s;
int a[500];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		a[s[i]]++;
	}
	for(int i='9';i>='0';i--){
		while(a[i]){
			cout<<i-'0';
			a[i]--;
		}
	}
	return 0;
}
