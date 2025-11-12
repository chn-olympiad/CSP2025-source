#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
bool p;
int t[10];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i]))t[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		if(i!=0&&t[i]>0)p=1;
		if(i==0&&!p){
			cout<<'0';
			return 0;
		}
		while(t[i]--)cout<<i;
	}
	return 0;
}
