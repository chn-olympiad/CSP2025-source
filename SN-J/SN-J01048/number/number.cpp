#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll tong[10];
ll yu;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s;
	for(char er:s){
		if(er>='0'&&er<='9'){
			yu=er-'0';
			tong[yu]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=tong[i];j++){
			cout<<i;
		}
	}
	return 0;
}
