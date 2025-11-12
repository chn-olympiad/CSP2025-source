#include<bits/stdc++.h>
using namespace std;
int a[1000100];
const int mod=998244353;
long long A(int a,int b){
	long long ans=1;
	for(int i=a-b+1;i<=a;i++){
		ans*=i;
		ans%=mod;
	}
	if(a==b){
		return ans;
	}
//	cout<<ans;
	return ans;
}
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>s;
	int cnt=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			cnt--;
		}
	}
	if(cnt<m){
		cout<<0;
		return 0;
	}
	long long ans=0;
	for(int i=m;i<=cnt;i++){
		ans+=A(n,i);
		ans%=mod;
	}
	cout<<ans;	
	
	return 0;
}