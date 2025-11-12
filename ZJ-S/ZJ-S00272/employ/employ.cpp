#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,ans=0;
	string s;
	cin>>n>>m;
	getline(cin,s);
	getline(cin,s);
	int f=0;
	for(int i=0;i<s.size();i++){
		if(s[i]==0){
			f=1;
		}
	}
	if(f==0){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=998244353;
		}
	}
	cout<<ans;
	return 0;
}
