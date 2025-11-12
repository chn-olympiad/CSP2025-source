#include <bits/stdc++.h>
//#defin a q;
using namespace std;
//priority_queue<int,vector<int>,less<int> >q;
long long T,n,ans=1;
const long long mod=998244353;
struct qw{
	string x,y;
}a[1000000],b[1000000];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		ans=ans*i%mod;
	}
	cout<<ans;
	return 0;
}
