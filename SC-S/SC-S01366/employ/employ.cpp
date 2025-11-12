#include<bits/stdc++.h>
using namespace std;
long long ans=1,n;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	for(long long i=n;i>=1;i--) ans=(ans*i%99824435);
	cout<<ans;
	return 0;
} 