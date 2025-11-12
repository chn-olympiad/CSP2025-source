#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int n,m;
string s;
int c[10005];
int cnt;
int ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int len=s.length();
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]>=len) cnt++;
	}
	cout<<cnt<<" ";
	for(int i=1;i<=cnt;i++){
		ans=ans*(i*(i+1));
		ans=ans%998244353;
	}
	cout<<ans%998244353;
	return 0;
}
