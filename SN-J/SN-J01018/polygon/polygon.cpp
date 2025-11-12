//SN-J01018  赵晗羽  西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
int n,a[5005],s,cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			s=max(s,a[i]);
			cnt+=a[i];
		}
		if(cnt>s*2)cout<<1;
		else cout<<0;
	}else{
		long long ss=1,sss=1,ssss=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=3;i<=n;i++){
			for(int j=n;j>n-i+1;j--){
				ss*=(1ll*j)%998244353;
				ss%=998244353;
			}
			for(int j=i;j>0;j--){
				sss*=(1ll*j)%998244353;
				sss%=998244353;
			}
			ssss+=(1ll*ss/(1ll*sss))%998244353;
			ssss=ssss*1ll;
			ssss%=998244353;
		}
		cout<<ssss%998244353;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
