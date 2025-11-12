//SN-J00738 王子铭 西安市曲江第一中学 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
bool cmp(ll a,ll b){
	return a > b; 
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	sort(s.begin(),s.end());
	for(ll i = s.size()-1;i >= 0;i --){
		if(s[i]>='a'&&s[i]<='z'){
			continue;
		}
		cout << s[i];
	}
	return 0; 
}
