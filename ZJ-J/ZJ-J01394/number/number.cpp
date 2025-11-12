#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll nbr[1000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s; cin >> s;
	for(int i=0;i<s.size();i++){
		nbr[s[i]]++;
	}
	for(int i='9';i>='0';i--){
		for(int j=0;j<nbr[i];j++) cout << int(i-'0');
	}
	return 0;
} 
