#include<bits/stdc++.h>
using namespace std;
string a;
int b[505],vis[505];
const int mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int p=0;
	cin>>a;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		if(p>=b[i]){
			p++;
			vis[i]=1;
		}
	}
	long long ans=1;
	for(int i=1;i<=n-p;i++){
		ans=ans*i%mod;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}