//考号：SN-J00509 姓名：李兴辰 学校：安康高新技术产业开发区九年制学校
#include<bits/stdc++.h>
using namespace std;
string s;
int a[10];
void solve(){
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[s[i]-'0']++;
		}
	} 
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	cin>>s;
	solve();
	for(int i=9;i>=0;i--){
		while(a[i]--)cout<<i;
	}
	return 0;
} 
