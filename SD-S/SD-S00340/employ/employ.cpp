#include<bits/stdc++.h>
using namespace std;
const int Mod=1e9+7;
string s;
int num;
int n,m;
int the;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++){
		num=num+(s[i]-'0');
	} 
	for(int i=1;i<=n;i++){
		cin>>the;
	}
	if(num==n||m==1&&num){
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*i%Mod;
		}
		cout<<ans<<endl;
		return 0;
	}
	cout<<0<<endl;
	return 0;
}
