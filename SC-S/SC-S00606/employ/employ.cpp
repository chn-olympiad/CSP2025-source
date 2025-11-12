#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	vector<long long> a(n+1);
	for(int i=0;i<n;i++)cin>>a[i];
	long long ans=1;
	for(int i=n;i>=2;i--){
		ans*=i;
	}
	cout<<ans;
	return 0;
} 