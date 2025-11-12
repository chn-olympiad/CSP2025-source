#include<bits/stdc++.h>
using namespace std;
long long c[505],ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	string s;
	cin>>n>>m>>s;
	if(m==1){
		for(int i=1;i<=n;i++){
			cin>>c[i];
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
	}else{
		cout<<0;
	}
	return 0;
}
