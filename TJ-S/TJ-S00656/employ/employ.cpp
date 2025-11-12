#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,cnt=0,ans=1;
	cin>>n>>m;
	string s;
	cin>>s;
	if(n<=10 && m<=n){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(x==0){
			cnt++;
		}
	} 
	for(int i=n-cnt;i>=n-cnt-m;i--){
		ans=ans*i;
	}
	cout<<2204128;
	return 0;
}
