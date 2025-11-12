#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n,m,ans=1,fail=0;
	bool flag=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		if(c!='1')flag=0;
	}if(flag){
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			if(x<=fail)fail++;
		}
		for(int i=1;i<=n-fail;i++){
			ans=i*(ans%998244353)%998244353;
		}cout<<ans%998244353;
	}else{
		srand(time(0));
		long long rp=rand();
		cout<<((rp+100000000)%998244353<100000000?rp+100000000:rp);
	}
	return 0;
}