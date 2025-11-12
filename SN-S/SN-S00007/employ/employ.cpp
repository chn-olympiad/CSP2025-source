#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
long long sum=1;
int n,m,a[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1') cnt++;
	}
	if(cnt<=m){
		for(int i=m;i<=cnt;i++){
			sum=(sum*i)%MOD;
		}
		cout<<sum;
	}else{
		for(int i=m;i<=cnt;i++){
			sum=(sum*i)%MOD;
		}
		for(int i=1;i<=m;i++){
			sum=(sum*i)%MOD;
		}
		cout<<sum+sum/6;
	}
	return 0;
}
