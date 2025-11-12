#include<bits/stdc++.h>
using namespace std;
int c[501];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	string s;
	cin>>n>>m;
	cin>>s;
	int cnt0=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0){
			cnt0++;
		}
	}
	bool flag=true;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			flag=false;
			break;
		}
	}
	long long ans=1;
	if(m>n-cnt0){
		cout<<0;
		return 0;
	}
	if(flag==true){
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans<<endl;
	}
	else{
		cout<<0;
	}
	return 0;
}

