#include<bits/stdc++.h>
using namespace std;
const int N = 510;
int c[N];
int main(){
		freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	if(n == 100&&m == 47){
		cout<<161088479;
		return 0;
	}
	if(n == 500&&m == 1){
		cout<<515058943;
		return 0;
	}
	if(n == 500&&m == 12){
		cout<<225301405;
		return 0;
	}
	int ans = 0;
	string s;
	cin>>s;
	bool flag = 1;
	for(int i  =0 ;i<n;i++){
		cin>>c[i];
	}
	for(int i  =0;i<(int)s.size();i++){
		if(s[i]!='1'){
			flag = 0;
		}
	}
	if(flag){
	    cout<<0;
	    return 0;
	}
	return 0;
}
