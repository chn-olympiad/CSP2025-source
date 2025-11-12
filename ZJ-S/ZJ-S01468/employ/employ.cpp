#include<bits/stdc++.h>
using namespace std;
long long n,m,i,s,ans,a[505];
string st;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	s=1;
	cin>>st;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0)ans++;
	}
	if(ans<m){
		cout<<0;
		return 0;
	}
	for(i=1;i<=ans;i++){
		s*=i;
		s%=998244353;
	}
	cout<<s;
}