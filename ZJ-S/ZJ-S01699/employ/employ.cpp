#include <bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,m;
long long ans=1;
string s;
long long jc(long long x){
	if(x==0||x==1)return 1;
	return x%M*jc(x-1)%M;
}
int main(){
	int cnt=0,x=0;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(x==0)cnt++;
	}
	if(n-cnt<m){cout<<0;return 0;}
	cout<<jc(n)%M;
	return 0;
}
