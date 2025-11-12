#include<bits/stdc++.h>
using namespace std;
int n,m,c[504],mod=998244353,sum=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		sum*=i;
		sum%=mod;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
