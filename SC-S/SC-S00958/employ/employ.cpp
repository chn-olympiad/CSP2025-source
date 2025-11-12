#include<bits/stdc++.h> 
#define ll long long
using namespace std;
const int mod=998244353;
ll n,m,sum=1,t1=0
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1') t1++;
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
	}
	if(t1==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		sum*=i;
		sum%=mod;
	}
	cout<<sum;
	return 0;
}