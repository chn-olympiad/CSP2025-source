#include<bits/stdc++.h>
using namespace std;
string s;
vector<int>a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>s;
	for(char i:s){
		if('0'<=i&&i<='9'){
			a.push_back(i-'0');
		}
	}
	sort(a.begin(),a.end(),greater<int>());
	for(int i:a){
		cout<<i;
	}
	return 0;
}