#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1010]; 
bool f(string s){
	int cnt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'){
			cnt++;
		}
	}
	if(cnt==s.size()){
		return 1;
	}
	return 0;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=s.size();i++){
		cin>>a[i];	
	}
	if(f(s)==1){
		int sum=1;
		for(int i=n;i>=m;i--){
			sum*=i%998244353;
			sum%=998244353;
		}
		cout<<sum;
		return 0;
	}
	return 0;
}