#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>s;
	int vis0=0;
	for(int i=0;i<n;i++){
		cin>>c[i];
		if(c[i]==0){
			vis0++; 
		}
	}
	int f=0;
	for(int i=0;i<s.size();i++){
		if(s[i]!='1'){
			f=1;
		}
	}
	long long ans=1;
	int vis=n-vis0;
	for(int i=1;i<=vis;i++){
		ans=(ans*i)%998244353;
	}
	cout<<ans<<endl;
	return 0;
}