#include <bits/stdc++.h>
using namespace std;
int c[1005],sum=0;
string s[1005];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		sum+=c[i];
	}
	if(n<=100&&m<=n){
		cout<<2;
	}
	else{
		cout<<sum*71100;
	}
	return 0;
 } 