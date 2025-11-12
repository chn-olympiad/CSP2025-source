#include<bits/stdc++.h>
using namespace std;
#define LL long long
int n,m;
int ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=2;i<=n;i++){
		ans=(ans*i)%998244353;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

