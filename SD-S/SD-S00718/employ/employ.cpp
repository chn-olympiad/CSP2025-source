#include<bits/stdc++.h>
using namespace std;
long long n,ans=1; 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	for(long long i=2;i<=n;i++)ans*=i;
	cout<<ans;
	return 0;
}

