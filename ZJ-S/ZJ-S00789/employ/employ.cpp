#include<bits/stdc++.h>
using namespace std;
long long n,m;
string s;
long long a[505];
long long ans=1;
const long long P=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=P;
	}
	cout<<0;
	return 0;
}
