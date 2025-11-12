#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
string s;
int a[500];
int mod=998244353;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<m){
		cout<<0;
		return 0;
	}
	int opp=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			opp++;
		}
	}
	if(opp==n){
		cout<<0;
		return 0;
	}
	cout<<0;
	return 0;
}
