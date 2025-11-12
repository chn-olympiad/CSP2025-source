#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
string s;
int pa[505];
unsigned long long A[505],inv[505];
int main(){

	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	//ios::sync_with_stdio(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>pa[i];
	inv[0]=1;
	for(int i=1;i<=n;i++){
		inv[i]=(inv[i-1]%mod*i%mod)%mod;
	}
	cout<<inv[n];
	fclose(stdin);
fclose(stdout);
	return 0;
}

