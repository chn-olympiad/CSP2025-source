#include<bits/stdc++.h>
using namespace std;
const long long maxx=998244353;
long long n,m;
string s;
long long a[100500];
long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(long long i=1;i<=n;i++)cin>>a[i];
	for(long long i=n;i>=n-m+1;i--){
		ans=ans*(i%maxx)%maxx;
	}
	cout<<ans;
	return 0;
}