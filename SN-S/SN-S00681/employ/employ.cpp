//赵晗羽 SN-S00681 西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,p[505],s1;
	string a;
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++)cin>>p[i];
	for(int i=n;i>n-m+1;i--){
		s1*=i;
		s1=1ll*s1;
		s1%=998244353;
	}
	cout<<s1;
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
