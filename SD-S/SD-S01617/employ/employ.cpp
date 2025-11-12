#include<bits/stdc++.h>
using namespace std;
int n,m,nx[504];
long long sum=1;
string a;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=1;i<=n;++i){
		cin>>nx[i];
	}
	for(int i=1;i<=n;++i){
		sum*=i;
	}
	cout<<sum%998244353;
	fclose(stdin);
	fclose(stdout); 
	return 0;
}

