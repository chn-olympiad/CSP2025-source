#include<bits/stdc++.h>
using namespace std;
int n,m,a[501],num[501];
long long ans;
const long long mod=998244353;
string s;
map<int,int> P;
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		P[a[i]]++;
	}
	for(auto p:P){
		long long temp=1;
		for(int i=1;i<=p.second;i++) temp*=i;
		ans+=temp;
		ans%=mod;
	}
	cout<<ans;
	return 0;
}