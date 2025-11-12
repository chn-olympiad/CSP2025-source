#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500],ans=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans*=i;
	}
	cout<<ans%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
