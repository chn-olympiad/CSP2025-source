#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
long long n,m,sum=1;
string s;
int main(){
	fast;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		long long x=0;
		cin>>x;
		sum*=x;
		sum%=998244353;
	}
	cout<<sum;
	return 0;
}

