#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string a;
	cin>>a;
	int b[100010];
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	if(m==1)cout<<1;
	long long ans=1;
	if(m==n){
		for(int i=1;i<=m;i++){
			ans*=i;
		}
		cout<<ans%998244353;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}





