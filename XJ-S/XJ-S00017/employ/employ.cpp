#include<bits/stdc++.h>
using namespace std;
long long n,m,sum=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=n,j=1;j<=m;i--,j++){
		sum*=i;
		sum%=998244353;
	} 
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
