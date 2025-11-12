#include<bits/stdc++.h>
using namespace std;
long long n,m,p=998244353,ans=1,s,a;
string ss;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>ss;
	for(int i=0;i<n;i++){
		cin>>a;
		s+=ss[i]-'0';
	}
	if(s<m){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=p;
	}
	cout<<ans;
	return 0;
} 
