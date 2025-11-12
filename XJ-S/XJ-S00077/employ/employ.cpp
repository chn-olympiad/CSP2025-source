#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int main(){
	freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
	int n,m,c[505];cin>>n>>m;
	string t;cin>>t;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]=='0'){
			flag=false;
		}
	}
	if(flag){
		long long sum=1,cnt=2,k=n-1;
		while(k--){
			sum=sum*cnt%MOD;
			cnt++;
		}
		cout<<sum%MOD;
	}
	else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
